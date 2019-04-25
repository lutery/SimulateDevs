import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        Depends { name: "Qt.core" }
        Depends { name: "Qt.network" }

        cpp.cxxLanguageVersion: "c++17"

        cpp.defines: [
            // The following define makes your compiler emit warnings if you use
            // any feature of Qt which as been marked deprecated (the exact warnings
            // depend on your compiler). Please consult the documentation of the
            // deprecated API in order to know how to port your code away from it.
            "QT_DEPRECATED_WARNINGS",

            // You can also make your code fail to compile if you use deprecated APIs.
            // In order to do so, uncomment the following line.
            // You can also select to disable deprecated APIs only up to a certain version of Qt.
            //"QT_DISABLE_DEPRECATED_BEFORE=0x060000" // disables all the APIs deprecated before Qt 6.0.0
        ]

        consoleApplication: true
        files: [
            "devclient.cpp",
            "devclient.h",
            "devdaemon.cpp",
            "devdaemon.h",
            "devicemanager.cpp",
            "devicemanager.h",
            "deviceorder.cpp",
            "deviceorder.h",
            "devicestatus.cpp",
            "devicestatus.h",
            "devinit.cpp",
            "devinit.h",
            "main.cpp",
            "printerorder.cpp",
            "printerorder.h",
            "toolutil.cpp",
            "toolutil.h",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }

        Group{
            name: "handler"
            files:[
                "abshandler.cpp",
                "abshandler.h",
                "devinfohandler.cpp",
                "devinfohandler.h",
                "devstatushandler.cpp",
                "devstatushandler.h",
                "unknownorderhandler.cpp",
                "unknownorderhandler.h",
            ]
        }

        Group{
            name: "verify"
            files: [
                "crc16ccitt.cpp",
                "crc16ccitt.h",
                "crc16xmodemverify.cpp",
                "crc16xmodemverify.h",
                "iverify.cpp",
                "iverify.h",
                "md5verify.cpp",
                "md5verify.h",
            ]
        }

    }
}
