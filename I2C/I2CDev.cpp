#include <I2CDev.hpp>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/i2c-dev.h>
#include <common.hpp>

const std::string I2CDev::DEFAULT_NAME = "/dev/i2c-1";

I2CDev::I2CDev(const std::string &devname, int address) {
    open(devname, address);
}

I2CDev::~I2CDev() {
    close();
}

void I2CDev::open(const std::string &devname, int address) {
    _fd = ::open(devname.c_str(), O_RDWR);
    if (_fd >= 0) {
        _addr = address;
        if (ioctl(_fd, I2C_SLAVE, address) < 0) {
            ERROR;
        }
    }
}

bool I2CDev::isOpen() const {
    return _fd > 0;
}

bool I2CDev::operator!() const {
    return isOpen();
}

void I2CDev::close() {
    if (isOpen()) {
        ::close(_fd);
        _fd = 0;
    }
}

void I2CDev::read(void *buf, size_t n) {
    if (::read(_fd, buf, n) < (ssize_t) n) {
        ERROR;
    }
}

void I2CDev::read(std::string &str, size_t n) {
    if (str.size() < n) {
        str.resize(n);
    }
    read(const_cast<char*>(str.data()), n);
}

void I2CDev::write(const void *buf, size_t n) {
    if (::write(_fd, buf, n) < (ssize_t) n) {
        ERROR;
    }
}

void I2CDev::write(const std::string &str, size_t n) {
    write(str.c_str(), n != 0 ? n : str.size());
}

int I2CDev::address() const {
    return _addr;
}
