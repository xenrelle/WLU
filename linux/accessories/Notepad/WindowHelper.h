#ifndef WINDOWHELPER_H
#define WINDOWHELPER_H

#include <QWidget>
#include <QApplication>
#include <QElapsedTimer>
#include <QDebug>
#include <type_traits>

class WindowHelper {
public:
    template<typename T, typename Func>
    static void launch(T* window, Func&& setupFunc) {
        window->setAttribute(Qt::WA_DontShowOnScreen, true);

        setupFunc(window);

        window->show();
        QApplication::processEvents();

        window->setAttribute(Qt::WA_DontShowOnScreen, false);
        window->hide();
        window->show();
    }
};

#endif