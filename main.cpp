#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWidget *window = new QWidget;
    w.setCentralWidget(window);

    auto textEditor = new QTextEdit();
    auto webViewer = new QWebEngineView();

    auto *layout = new QHBoxLayout(window);
    layout->addWidget(textEditor, 1);
    layout->addWidget(webViewer, 1);

    textEditor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    webViewer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    webViewer->setHtml("<h1>Hello</h1>");
    QObject::connect(textEditor, &QTextEdit::textChanged, webViewer, [textEditor, webViewer](){
        QString html = textEditor->toPlainText();
        webViewer->setHtml(html);
    });

    w.show();
    return a.exec();
}
