/*
 * InputLeap -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2002 Chris Schoeneman
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "base/Event.h"
#include "base/EventTypes.h"

class NetworkAddress;

//! Generic socket interface
/*!
This interface defines the methods common to all network sockets.
Generated events use \c this as the target.
*/
class ISocket {
public:
    virtual ~ISocket() { }

    //! @name manipulators
    //@{

    //! Bind socket to address
    /*!
    Binds the socket to a particular address.
    */
    virtual void        bind(const NetworkAddress&) = 0;

    //! Close socket
    /*!
    Closes the socket.  This should flush the output stream.
    */
    virtual void        close() = 0;

    //@}
    //! @name accessors
    //@{

    //! Get event target
    /*!
    Returns the event target for events generated by this socket.
    */
    virtual void*        getEventTarget() const = 0;

    //@}
};
