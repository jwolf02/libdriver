#ifndef __I2C_HPP
#define __I2C_HPP

#include <string>
#include <cstddef>

class I2CDev {
public:

    static const std::string DEFAULT_NAME;

    I2CDev() = default;

    I2CDev(const std::string &devname, int address);

    ~I2CDev();

    void open(const std::string &devname, int address);

    bool isOpen() const;

    bool operator!() const;

    void close();

    void read(void *buf, size_t n);

    void read(std::string &str, size_t n);

    void write(const void *buf, size_t n);

    void write(const std::string &str, size_t n=0);

    int address() const;

private:

    int _fd = 0;

    int _addr = 0;

};

#endif // __I2C_HPP
