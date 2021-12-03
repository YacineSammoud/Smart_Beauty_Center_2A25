/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pt_ajouter_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 25), // "on_push_supprimer_clicked"
QT_MOC_LITERAL(4, 60, 26), // "on_bouton_modifier_clicked"
QT_MOC_LITERAL(5, 87, 19), // "on_trie_nom_clicked"
QT_MOC_LITERAL(6, 107, 24), // "on_pushButton_id_clicked"
QT_MOC_LITERAL(7, 132, 28), // "on_pushButton_prenom_clicked"
QT_MOC_LITERAL(8, 161, 25), // "on_pushButton_pdf_clicked"
QT_MOC_LITERAL(9, 187, 26), // "on_pushButton_stat_clicked"
QT_MOC_LITERAL(10, 214, 25), // "on_pushButton_cam_clicked"
QT_MOC_LITERAL(11, 240, 22), // "on_id_supp_textChanged"
QT_MOC_LITERAL(12, 263, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(13, 286, 4), // "arg1"
QT_MOC_LITERAL(14, 291, 19) // "on_employes_clicked"

    },
    "MainWindow\0on_pt_ajouter_clicked\0\0"
    "on_push_supprimer_clicked\0"
    "on_bouton_modifier_clicked\0"
    "on_trie_nom_clicked\0on_pushButton_id_clicked\0"
    "on_pushButton_prenom_clicked\0"
    "on_pushButton_pdf_clicked\0"
    "on_pushButton_stat_clicked\0"
    "on_pushButton_cam_clicked\0"
    "on_id_supp_textChanged\0on_lineEdit_textEdited\0"
    "arg1\0on_employes_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pt_ajouter_clicked(); break;
        case 1: _t->on_push_supprimer_clicked(); break;
        case 2: _t->on_bouton_modifier_clicked(); break;
        case 3: _t->on_trie_nom_clicked(); break;
        case 4: _t->on_pushButton_id_clicked(); break;
        case 5: _t->on_pushButton_prenom_clicked(); break;
        case 6: _t->on_pushButton_pdf_clicked(); break;
        case 7: _t->on_pushButton_stat_clicked(); break;
        case 8: _t->on_pushButton_cam_clicked(); break;
        //case 9: _t->on_id_supp_textChanged(); break;
        case 10: _t->on_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        //case 11: _t->on_employes_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
