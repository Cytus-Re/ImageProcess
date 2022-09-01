/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Nov 24 14:34:31 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../opencv_test/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      30,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      67,   11,   11,   11, 0x08,
      89,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     210,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,
     294,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_load_clicked()\0"
    "on_close_clicked()\0on_salt_clicked()\0"
    "on_gaussian_clicked()\0on_blur_clicked()\0"
    "on_g_blur_clicked()\0on_m_blur_clicked()\0"
    "on_para_clicked()\0on_para_2_clicked()\0"
    "on_exponential_clicked()\0on_random_clicked()\0"
    "on_export_file_clicked()\0on_bilater_clicked()\0"
    "on_c_av_clicked()\0on_c_med_clicked()\0"
    "on_c_gau_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_load_clicked(); break;
        case 1: _t->on_close_clicked(); break;
        case 2: _t->on_salt_clicked(); break;
        case 3: _t->on_gaussian_clicked(); break;
        case 4: _t->on_blur_clicked(); break;
        case 5: _t->on_g_blur_clicked(); break;
        case 6: _t->on_m_blur_clicked(); break;
        case 7: _t->on_para_clicked(); break;
        case 8: _t->on_para_2_clicked(); break;
        case 9: _t->on_exponential_clicked(); break;
        case 10: _t->on_random_clicked(); break;
        case 11: _t->on_export_file_clicked(); break;
        case 12: _t->on_bilater_clicked(); break;
        case 13: _t->on_c_av_clicked(); break;
        case 14: _t->on_c_med_clicked(); break;
        case 15: _t->on_c_gau_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
