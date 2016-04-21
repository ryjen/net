#ifndef ARG3_NET_SOCKETFACTORY_H
#define ARG3_NET_SOCKETFACTORY_H

#include "buffered_socket.h"

#include <memory>

namespace arg3
{
    namespace net
    {
        class buffered_socket;
        class socket_server;

        /* factory class to control sockets in a server */
        class socket_factory
        {
           public:
            /* creates a buffered socket from a raw socket */
            virtual std::shared_ptr<buffered_socket> create_socket(socket_server *server, SOCKET sock, const struct sockaddr_storage &addr) = 0;

            virtual ~socket_factory()
            {
            }
        };

        namespace detail
        {
            /* default implementation of a socket factory */
            class default_socket_factory : public socket_factory
            {
               public:
                virtual std::shared_ptr<buffered_socket> create_socket(socket_server *server, SOCKET sock, const struct sockaddr_storage &addr);
            };
        }

        /* default factory instance */
        extern detail::default_socket_factory default_socket_factory;
    }
}

#endif
