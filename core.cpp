#include <QFile>
#include <QTextStream>

QString get_file_content(QString filename)
{
    QString file_content;

    QFile file(filename);
    if (file.open(QFile::ReadOnly))
    {
	file_content = file.readAll();
    }

    return file_content;
}
