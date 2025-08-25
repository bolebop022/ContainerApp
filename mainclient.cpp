#include "mainclient.h"
#include "postwidget.h"
#include "mainwidget.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLayout>
#include <QStatusBar>
#include <QMessageBox>
#include <QCloseEvent>
#include <qpushbutton.h>
#include <QTextEdit>

MainClient::MainClient(QWidget *parent)
    : QMainWindow(parent)
{

    // Initialize window
    setCentralWidget(setUpTabWindows());
    setWindowTitle("Container");
    setMaximumSize(600, 400);
    setWindowState(Qt::WindowMaximized);
    statusBar()->showMessage("Ready");
}

MainClient::~MainClient()
{
    // Tidy up pointers, if required
}


QTabWidget* MainClient::setUpTabWindows()
{
    // Set up tab windows
    QTabWidget *tabContainers = new QTabWidget(this);
    tabContainers->addTab(new MainWidget(), "Containers");
    tabContainers->addTab(new PostWidget(), "Post XML");
    return tabContainers;
}


