//****************************************************************************
// Purpose: Fixture for QUTEST
// Last Updated for Version: 6.2.0
// Date of the Last Update:  2018-03-17
//
//                    Q u a n t u m     L e a P s
//                    ---------------------------
//                    innovating embedded systems
//
// Copyright (C) 2002-2018 Quantum Leaps, LLC. All rights reserved.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Alternatively, this program may be distributed and modified under the
// terms of Quantum Leaps commercial licenses, which expressly supersede
// the GNU General Public License and are specifically designed for
// licensees interested in retaining the proprietary status of their code.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//
// Contact information:
// https://www.state-machine.com
// mailto:info@state-machine.com
//****************************************************************************
#include "qpcpp.h"
#include "defer.h"
#include <stdio.h>

Q_DEFINE_THIS_FILE

//............................................................................
int main(int argc, char *argv[]) {
    static QF_MPOOL_EL(RequestEvt) smlPoolSto[10]; // storage for small pool
    static QEvt const *tserverQSto[10]; // event queue storage for TServer

    (void)argc;  // unused parameter
    (void)argv;  // unused parameter

    QF::init(); // initialize the framework and the underlying RTOS/OS
    Q_ALLEGE(QS_INIT((void *)0)); // initialize the QS software tracing

    // dictionaries...
    QS_OBJ_DICTIONARY(smlPoolSto);
    QS_OBJ_DICTIONARY(tserverQSto);

    // pause execution of the test and wait for the test script to continue
    QS_TEST_PAUSE();

    // publish-subscribe not used, no call to QF::psInit()

    // initialize event pools...
    QF::poolInit(smlPoolSto, sizeof(smlPoolSto), sizeof(smlPoolSto[0]));

    //start the active objects...
    AO_TServer->start(1U,
                      tserverQSto, Q_DIM(tserverQSto),
                      (void *)0, 0U, (QEvt *)0);

    return QF::run();
}

//----------------------------------------------------------------------------
void QS::onTestSetup(void) {
}
//............................................................................
void QS::onTestTeardown(void) {
}
//............................................................................
void QS::onCommand(uint8_t cmdId,
                   uint32_t param1, uint32_t param2, uint32_t param3)
{
    (void)param1;
    (void)param2;
    (void)param3;

    //printf("<TARGET> Command id=%d param=%d\n", (int)cmdId, (int)param);
    switch (cmdId) {
       case 0U: {
           break;
       }
       default:
           break;
    }
}

//............................................................................
//host callback function to "massage" the event, if necessary
void QS::onTestEvt(QEvt *e) {
    (void)e;
#ifdef Q_HOST  // is this test compiled for a desktop Host computer?
#else // this test is compiled for an embedded Target system
#endif
}

