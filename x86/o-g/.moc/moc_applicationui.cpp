/****************************************************************************
** Meta object code from reading C++ file 'applicationui.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/applicationui.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RSSFeed[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       3,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      22,    8,    8,    8, 0x05,
      37,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,    8,    8,    8, 0x0a,
      67,   61,    8,    8, 0x08,
      92,    8,    8,    8, 0x08,
     104,    8,    8,    8, 0x08,

 // properties: name, type, flags
     147,  139, 0x0a495103,
     151,  139, 0x0a495001,
     162,  157, 0x01495001,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

static const char qt_meta_stringdata_RSSFeed[] = {
    "RSSFeed\0\0urlChanged()\0feedsChanged()\0"
    "activeChanged()\0fetch()\0reply\0"
    "finished(QNetworkReply*)\0readyRead()\0"
    "error(QNetworkReply::NetworkError)\0"
    "QString\0url\0feeds\0bool\0active\0"
};

void RSSFeed::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RSSFeed *_t = static_cast<RSSFeed *>(_o);
        switch (_id) {
        case 0: _t->urlChanged(); break;
        case 1: _t->feedsChanged(); break;
        case 2: _t->activeChanged(); break;
        case 3: _t->fetch(); break;
        case 4: _t->finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->readyRead(); break;
        case 6: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RSSFeed::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RSSFeed::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RSSFeed,
      qt_meta_data_RSSFeed, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RSSFeed::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RSSFeed::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RSSFeed::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RSSFeed))
        return static_cast<void*>(const_cast< RSSFeed*>(this));
    return QObject::qt_metacast(_clname);
}

int RSSFeed::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = url(); break;
        case 1: *reinterpret_cast< QString*>(_v) = feeds(); break;
        case 2: *reinterpret_cast< bool*>(_v) = active(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setUrl(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RSSFeed::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RSSFeed::feedsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RSSFeed::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
