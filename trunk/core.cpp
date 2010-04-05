#include <QFile>

QString get_file_content(QString filename)
{
    QString file_content;

    QFile file(filename);
    if (file.open(QFile::ReadWrite))
	file_content = file.readAll();

    file.close();
    return file_content;
}
