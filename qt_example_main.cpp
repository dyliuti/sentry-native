#include <sentry.h>
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    // 初始化 Sentry
    sentry_options_t *options = sentry_options_new();
    sentry_options_set_dsn(options, "https://your-dsn@sentry.io/project-id");
    sentry_options_set_release(options, "1.0.0");
    sentry_init(options);

    QApplication app(argc, argv);
    QMainWindow window;
    window.show();

    int result = app.exec();

    // 关闭 Sentry
    sentry_close();
    return result;
}
