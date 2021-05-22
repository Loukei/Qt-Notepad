#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
namespace Ui {
class MainWindow;
}

/*foward declaration*/
class TabWidget;
class TextEditor;
class QSettings;
class RecentFiles;
class SearchWidget;

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow
     * \param parent
     * \details 1.讀取最近的檔案 2.載入上一次的設定 3. 初始化UI元件
     */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    /*!
     * \brief openFile [TODO] 開啟指定路徑的檔案
     * \param fpath
     * \return currentIndex 也就是產生的Tab編號
     */
    int openFile(const QString &fpath);

protected:
    void closeEvent(QCloseEvent *event) override;
    /*!
     * \brief dragEnterEvent 檢查拖曳進來的檔案類型是否為文字檔，若是才可接受事件
     * \param event
     */
    virtual void dragEnterEvent(QDragEnterEvent *event) override; //! drag to load
    /*!
     * \brief dropEvent 確認拖曳進來的檔案數量，並呼叫openFile()創建分頁並開啟檔案
     * \param event
     */
    virtual void dropEvent(QDropEvent *event) override;

private:
    Ui::MainWindow *ui;

    /*child widget*/
    //! 提供多分頁功能的元件
    TabWidget *tabwidget;
    //! 提供搜尋功能的元件
    SearchWidget *searchwidget;

    /*Variables*/
    //! 儲存APP名稱的常數字串
    const char *apptitle = "NotePad";
    //! 負責管理各項設定的存讀檔
    QSettings *settings;
    //! 決定recent file列表的大小的常數
    //! 使用enum定義一個類別內編譯期常數，否則array無法接受
    enum {maxRecent = 10};
    //! 保存最近開啟過的檔案路徑(String list)
    //! 同時具有讀寫到Settings的功能
    //! QSharedPointer保證會自動刪除
    QSharedPointer<RecentFiles> recentFiles;

    /*Actions*/
    QAction* action_SubMenuRecentFile;
    QAction* action_RecentFileArray[maxRecent];

    /*Function*/
    void initialActions();
    void initialMenus();
    void initialToolBars();
    void initialStatusBar();
    void initialTabWidget();
    void initailSearchWidget();
    TextEditor* createEditor(QWidget *parent);

    //! File I/O
    bool maybeSave(TextEditor *editor);
    //! File I/O

    //! QSettings
    void loadSettings();
    void saveSettings();
    //! QSettings

    QString getCurrentFolder();
    void resetMainWindowTitle(const QString &fpath);
    void updateMenus();
    TextEditor* currentTextEditor();

private slots:
    //! File I/O
    void on_newFile();
    void on_openFile();
    void on_saveFile();
    void on_saveAsFile();
    //! File I/O

    void on_TabWidget_tabCloseRequested(int index); //!tab關閉按鈕按下
    void on_TabWidget_currentChanged(int index);    //!tabwidget切換tab
    void on_documentWasModified();                  //!檔案內容修改

    //! click board
    void on_UndoAct_triggered();
    void on_RedoAct_triggered();
    void on_cutAct_triggered();
    void on_copyAct_triggered();
    void on_pasteAct_triggered();
    void on_deleteAct_triggered();
    void on_selectAllAct_triggered();
    //! click board

    //! recent File
    void on_openRecentFile();
    void on_menuRecentFile_aboutToShow();
    void on_clearRecentFileAct_triggered();
    //! recent File

    //! Find & Replace
    void on_FindOrReplaceAct_triggered();
    void on_SearchWidget_findNextButtonClicked();
    void on_SearchWidget_findPreviousButtonClicked();
    void on_SearchWidget_replaceButtonClicked();
    void on_SearchWidget_replaceAllButtonClicked();
    //! Find & Replace

    void on_setFont_triggered(); //! set editor textfont

    void on_reopenEncoding();
    void on_saveEncoding();
};
#endif // MAINWINDOW_H

