#include <QFile>
#include <core.h>

QString get_file_content(QString filename)
{
    QString file_content;

    QFile file(filename);
    if (file.open(QFile::ReadOnly))
	file_content = file.readAll();

    file.close();
    return file_content;
}


/****************************************************************/
/****************  Makefile class implementation ****************/

// Default constructor

//WARNING: This is only stub now.
// Later it should process reduino configuration file,
// current project configuration and previous user sessions

#define DZEBAN_PATH "/usr/share/arduino"    //Sorry for that, guys ;-)
Makefile::Makefile()
{
    arduino_libs_path = DZEBAN_PATH;

    board_type = MEGA;

    OS = NIX;

    // No flags by default
    cc_flags = "";
}

Makefile::~Makefile()
{

}
