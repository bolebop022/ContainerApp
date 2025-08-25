#ifndef MAINCLIENT_H
#define MAINCLIENT_H

#include <QMainWindow>
#include <QTabWidget>

class QAction;
class QMenu;
class QToolBar;

class MainClient : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainClient(QWidget *parent = nullptr);
    ~MainClient();


public slots:


private:
    QTabWidget* setUpTabWindows();

};

#endif // MAINCLIENT_H
