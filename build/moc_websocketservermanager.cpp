/****************************************************************************
** Meta object code from reading C++ file 'websocketservermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server/websocketservermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'websocketservermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WebSocketServerManager_t {
    QByteArrayData data[36];
    char stringdata0[545];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebSocketServerManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebSocketServerManager_t qt_meta_stringdata_WebSocketServerManager = {
    {
QT_MOC_LITERAL(0, 0, 22), // "WebSocketServerManager"
QT_MOC_LITERAL(1, 23, 15), // "signal_conncted"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 2), // "ip"
QT_MOC_LITERAL(4, 43, 4), // "port"
QT_MOC_LITERAL(5, 48, 18), // "signal_disconncted"
QT_MOC_LITERAL(6, 67, 28), // "signal_sendTextMessageResult"
QT_MOC_LITERAL(7, 96, 6), // "result"
QT_MOC_LITERAL(8, 103, 30), // "signal_sendBinaryMessageResult"
QT_MOC_LITERAL(9, 134, 12), // "signal_error"
QT_MOC_LITERAL(10, 147, 11), // "errorString"
QT_MOC_LITERAL(11, 159, 24), // "signal_textFrameReceived"
QT_MOC_LITERAL(12, 184, 5), // "frame"
QT_MOC_LITERAL(13, 190, 11), // "isLastFrame"
QT_MOC_LITERAL(14, 202, 26), // "signal_textMessageReceived"
QT_MOC_LITERAL(15, 229, 7), // "message"
QT_MOC_LITERAL(16, 237, 12), // "signal_close"
QT_MOC_LITERAL(17, 250, 10), // "slot_start"
QT_MOC_LITERAL(18, 261, 12), // "QHostAddress"
QT_MOC_LITERAL(19, 274, 11), // "hostAddress"
QT_MOC_LITERAL(20, 286, 9), // "slot_stop"
QT_MOC_LITERAL(21, 296, 13), // "slot_sendData"
QT_MOC_LITERAL(22, 310, 18), // "slot_newConnection"
QT_MOC_LITERAL(23, 329, 16), // "slot_serverError"
QT_MOC_LITERAL(24, 346, 29), // "QWebSocketProtocol::CloseCode"
QT_MOC_LITERAL(25, 376, 9), // "closeCode"
QT_MOC_LITERAL(26, 386, 11), // "slot_closed"
QT_MOC_LITERAL(27, 398, 17), // "slot_disconnected"
QT_MOC_LITERAL(28, 416, 10), // "slot_error"
QT_MOC_LITERAL(29, 427, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(30, 456, 5), // "error"
QT_MOC_LITERAL(31, 462, 22), // "slot_textFrameReceived"
QT_MOC_LITERAL(32, 485, 24), // "slot_textMessageReceived"
QT_MOC_LITERAL(33, 510, 13), // "replyFinished"
QT_MOC_LITERAL(34, 524, 14), // "QNetworkReply*"
QT_MOC_LITERAL(35, 539, 5) // "reply"

    },
    "WebSocketServerManager\0signal_conncted\0"
    "\0ip\0port\0signal_disconncted\0"
    "signal_sendTextMessageResult\0result\0"
    "signal_sendBinaryMessageResult\0"
    "signal_error\0errorString\0"
    "signal_textFrameReceived\0frame\0"
    "isLastFrame\0signal_textMessageReceived\0"
    "message\0signal_close\0slot_start\0"
    "QHostAddress\0hostAddress\0slot_stop\0"
    "slot_sendData\0slot_newConnection\0"
    "slot_serverError\0QWebSocketProtocol::CloseCode\0"
    "closeCode\0slot_closed\0slot_disconnected\0"
    "slot_error\0QAbstractSocket::SocketError\0"
    "error\0slot_textFrameReceived\0"
    "slot_textMessageReceived\0replyFinished\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebSocketServerManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  119,    2, 0x06 /* Public */,
       5,    2,  124,    2, 0x06 /* Public */,
       6,    3,  129,    2, 0x06 /* Public */,
       8,    3,  136,    2, 0x06 /* Public */,
       9,    3,  143,    2, 0x06 /* Public */,
      11,    4,  150,    2, 0x06 /* Public */,
      14,    3,  159,    2, 0x06 /* Public */,
      16,    0,  166,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    2,  167,    2, 0x0a /* Public */,
      17,    1,  172,    2, 0x2a /* Public | MethodCloned */,
      17,    0,  175,    2, 0x2a /* Public | MethodCloned */,
      20,    0,  176,    2, 0x0a /* Public */,
      21,    3,  177,    2, 0x0a /* Public */,
      22,    0,  184,    2, 0x09 /* Protected */,
      23,    1,  185,    2, 0x09 /* Protected */,
      26,    0,  188,    2, 0x09 /* Protected */,
      27,    0,  189,    2, 0x09 /* Protected */,
      28,    1,  190,    2, 0x09 /* Protected */,
      31,    2,  193,    2, 0x09 /* Protected */,
      32,    1,  198,    2, 0x09 /* Protected */,
      33,    1,  201,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Bool,    3,    4,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Bool,    3,    4,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString,    3,    4,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString, QMetaType::Bool,    3,    4,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString,    3,    4,   15,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 18, QMetaType::Int,   19,    4,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 34,   35,

       0        // eod
};

void WebSocketServerManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebSocketServerManager *_t = static_cast<WebSocketServerManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_conncted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2]))); break;
        case 1: _t->signal_disconncted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2]))); break;
        case 2: _t->signal_sendTextMessageResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->signal_sendBinaryMessageResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->signal_error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->signal_textFrameReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 6: _t->signal_textMessageReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->signal_close(); break;
        case 8: _t->slot_start((*reinterpret_cast< QHostAddress(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2]))); break;
        case 9: _t->slot_start((*reinterpret_cast< QHostAddress(*)>(_a[1]))); break;
        case 10: _t->slot_start(); break;
        case 11: _t->slot_stop(); break;
        case 12: _t->slot_sendData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 13: _t->slot_newConnection(); break;
        case 14: _t->slot_serverError((*reinterpret_cast< QWebSocketProtocol::CloseCode(*)>(_a[1]))); break;
        case 15: _t->slot_closed(); break;
        case 16: _t->slot_disconnected(); break;
        case 17: _t->slot_error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 18: _t->slot_textFrameReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 19: _t->slot_textMessageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WebSocketServerManager::*_t)(QString , qint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServerManager::signal_conncted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WebSocketServerManager::*_t)(QString , qint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServerManager::signal_disconncted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WebSocketServerManager::*_t)(QString , quint32 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServerManager::signal_sendTextMessageResult)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WebSocketServerManager::*_t)(QString , quint32 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServerManager::signal_sendBinaryMessageResult)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (WebSocketServerManager::*_t)(QString , quint32 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServerManager::signal_error)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (WebSocketServerManager::*_t)(QString , quint32 , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServerManager::signal_textFrameReceived)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (WebSocketServerManager::*_t)(QString , quint32 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServerManager::signal_textMessageReceived)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (WebSocketServerManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServerManager::signal_close)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject WebSocketServerManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebSocketServerManager.data,
      qt_meta_data_WebSocketServerManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WebSocketServerManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebSocketServerManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WebSocketServerManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WebSocketServerManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void WebSocketServerManager::signal_conncted(QString _t1, qint32 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WebSocketServerManager::signal_disconncted(QString _t1, qint32 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WebSocketServerManager::signal_sendTextMessageResult(QString _t1, quint32 _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WebSocketServerManager::signal_sendBinaryMessageResult(QString _t1, quint32 _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WebSocketServerManager::signal_error(QString _t1, quint32 _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WebSocketServerManager::signal_textFrameReceived(QString _t1, quint32 _t2, QString _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void WebSocketServerManager::signal_textMessageReceived(QString _t1, quint32 _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void WebSocketServerManager::signal_close()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
