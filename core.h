#ifndef CORE_H
#define CORE_H

QString get_file_content(QString filename);


enum OPERATING_SYSTEM_TYPES {WIN, NIX, MAC};

enum BOARD_TYPES {DUE168, DUE328, MEGA, MINI, BT, LILY168, LILY328, PRO168, PRO328, NG8, NG168};

/*
 Class for building and uploading code to board


    To build and upload code to board we need to know next things:

    1. OS								|
    2. Path to wiring libs						|=> FOR BUILD
    3. Board/controller model						|
    4. Compiler flags (need to be realized from made up Makefile)	|

    5. How device connected (address like /dev/ttyUSB0 or COM3 or etc.) |=> FOR UPLOAD

  */
class Makefile
{
private:
    OPERATING_SYSTEM_TYPES OS;	    // OS type(e.g. Mac)
    QString arduino_libs_path;	    // Path to wiring libs
    BOARD_TYPES board_type;	    // Board type(e.g. Arduino duemilanove with ATMega 328)
    QString cc_flags;		    // Compiler flags

protected:
    QString makefile;	//class-member, that holds makefile

public:
    Makefile();
    ~Makefile();
};

#endif // CORE_H
