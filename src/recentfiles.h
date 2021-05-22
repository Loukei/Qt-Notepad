#ifndef RECENTFILES_H
#define RECENTFILES_H
#include <QStringList>
class QSettings;

/*!
 * \brief The RecentFiles class 繼承自QStringList，
 * 提供了讀寫QSetting的功能
 * 保存了recent file在Settings裡的key值
 * prepend函數則保證每個寫入RecentFiles的資料一定不會重複並堆疊在最上方
 */
class RecentFiles : public QStringList
{
public:
    RecentFiles();
    ~RecentFiles();

    //! 讀取setting到string list
    bool readSettings(QSettings *settings);
    //! 寫入到Setting
    bool writeSettings(QSettings *settings);
    bool prepend(const QString &filename);
    inline static QString recentFilesKey(){return QStringLiteral("RecentFileList");}
    inline static QString fileKey(){return QStringLiteral("filePath");}
};

#endif // RECENTFILES_H
