#include <iostream>
#include <D:\Chrome\mysql-connector-c++-8.3.0-winx64\mysql-connector-c++-8.3.0-winx64\include\mysql\jdbc.h>

using namespace std;

int main() {
    try {
        // Create a connection
        sql::Driver *driver;
        sql::Connection *con;

        // Replace 'your_host', 'your_username', 'your_password', and 'your_database' with your MySQL server details
        driver = get_driver_instance();
        con = driver->connect("tcp://your_host:3306", "root", "2021");

        // Connect to the MySQL database
        con->setSchema("your_database");

        cout << "Connected to MySQL database successfully!" << endl;

        // Clean up
        delete con;

    } catch (sql::SQLException &e) {
        // Handle any MySQL errors
        cout << "MySQL error: " << e.what() << endl;
    }

    return 0;
}
