#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <gphoto2/gphoto2.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Camera		*camera;
    int		ret;
    char		*owner;
    GPContext	*context;
    CameraText	text;

    /* This is the mandatory part */
    context = gp_context_new();
    gp_camera_new (&camera);

    //detect and open first aviable camera
    ret = gp_camera_init (camera, context);
    if (ret < GP_OK)
    {
        qDebug() <<  "No camera auto detected.\n";

        gp_camera_free (camera);

    }

    ret = gp_camera_get_summary (camera, &text, context);
    if (ret < GP_OK) {
        qDebug() <<"Camera failed retrieving summary.\n";
        gp_camera_free (camera);

    }
    printf("Summary:\n%s\n", text.text);
}

MainWindow::~MainWindow()
{
    delete ui;
}
