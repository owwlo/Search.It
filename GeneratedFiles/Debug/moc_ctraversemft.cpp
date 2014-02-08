/****************************************************************************
** Meta object code from reading C++ file 'ctraversemft.h'
**
** Created: Sat May 28 14:57:06 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ctraversemft.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ctraversemft.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CTraverseMFT[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CTraverseMFT[] = {
    "CTraverseMFT\0\0Signal_OnTraverseDone()\0"
};

void CTraverseMFT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CTraverseMFT *_t = static_cast<CTraverseMFT *>(_o);
        switch (_id) {
        case 0: _t->Signal_OnTraverseDone(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CTraverseMFT::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CTraverseMFT::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CTraverseMFT,
      qt_meta_data_CTraverseMFT, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CTraverseMFT::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CTraverseMFT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CTraverseMFT::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CTraverseMFT))
        return static_cast<void*>(const_cast< CTraverseMFT*>(this));
    return QThread::qt_metacast(_clname);
}

int CTraverseMFT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void CTraverseMFT::Signal_OnTraverseDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
