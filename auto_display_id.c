#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>  // Add this include for close()

int main() {
    int i2c_bus;
    int n;

// open the bus
    i2c_bus = open("/dev/i2c-3", O_RDWR); // open I2C bus 3, in read write mode. File handle will be i2c_bus.

    if (i2c_bus < 0) {
        perror("Error opening i2c_bus");
        return 1;
    }

// Send data to slave address 0x70
    if (ioctl(i2c_bus, I2C_SLAVE, 0x70) < 0) {
        perror("Error setting slave address 0x70");
        close(i2c_bus);
        return 1;
    }
    
// Data to be sent to slave address 0x70
    uint8_t data_70[] = {0x58}; 
    n = write(i2c_bus, data_70, sizeof(data_70));
    if (n != sizeof(data_70)) {
        perror("Error writing to i2c bus (slave address 0x70)");
        close(i2c_bus);
        return 1;
    }


// Send data to another slave address 0x78
    if (ioctl(i2c_bus, I2C_SLAVE, 0x78) < 0) {
        perror("Error setting slave address 0x78");
        close(i2c_bus);
        return 1;
    }

// Data to be sent to slave address 0x78
    uint8_t data_78[] = {0x58}; 
    n = write(i2c_bus, data_78, sizeof(data_78));
    if (n != sizeof(data_78)) {
        perror("Error writing to i2c bus (slave address 0x78)");
        close(i2c_bus);
        return 1;
    }

// Send data to another slave address 0x88
    if (ioctl(i2c_bus, I2C_SLAVE, 0x88) < 0) {
        perror("Error setting slave address 0x88");
        close(i2c_bus);
        return 1;
    }

// Data to be sent to slave address 0x88
    uint8_t data_88[] = {0x00}; 
    n = write(i2c_bus, data_88, sizeof(data_88));
    if (n != sizeof(data_88)) {
        perror("Error writing to i2c bus (slave address 0x88)");
        close(i2c_bus);
        return 1;
    }

// Send data to another slave address 0x71
    if (ioctl(i2c_bus, I2C_SLAVE, 0x71) < 0) {
        perror("Error setting slave address 0x71");
        close(i2c_bus);
        return 1;
    }

// Data to be sent to slave address 0x71
    uint8_t data_71[] = {0x24}; 
    n = write(i2c_bus, data_71, sizeof(data_71));
    if (n != sizeof(data_71)) {
        perror("Error writing to i2c bus (slave address 0x71)");
        close(i2c_bus);
        return 1;
    }

// Send data to another slave address 0x79
    if (ioctl(i2c_bus, I2C_SLAVE, 0x79) < 0) {
        perror("Error setting slave address 0x79");
        close(i2c_bus);
        return 1;
    }

// Data to be sent to slave address 0x71
    uint8_t data_79[] = {0x24}; 
    n = write(i2c_bus, data_79, sizeof(data_79));
    if (n != sizeof(data_79)) {
        perror("Error writing to i2c bus (slave address 0x79)");
        close(i2c_bus);
        return 1;
    }

// Send data to another slave address 0x7
    if (ioctl(i2c_bus, I2C_SLAVE, 0x7) < 0) {
        perror("Error setting slave address 0x7");
        close(i2c_bus);
        return 1;
    }

// Data to be sent to slave address 0x7
    uint8_t data_7[] = {0x88}; 
    n = write(i2c_bus, data_7, sizeof(data_7));
    if (n != sizeof(data_7)) {
        perror("Error writing to i2c bus (slave address 0x7)");
        close(i2c_bus);
        return 1;
    }


// Read data from slave address 0x5
    uint8_t read_data=0x5;
    n = read(i2c_bus, &read_data, sizeof(read_data));
    if (n != sizeof(read_data)) {
        perror("Error reading from i2c bus (slave address 0x5)");
        close(i2c_bus);
        return 1;
    }

    printf("Data read from slave address 0x5: 0x%02X\n", read_data);


    close(i2c_bus);
    return 0;
}

