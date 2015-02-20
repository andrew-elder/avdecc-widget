/*
 * Licensed under the MIT License (MIT)
 *
 * Copyright (c) 2013 AudioScience Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * end_station.h
 *
 * Public End Station interface class
 */

#pragma once

#include <stdint.h>
#include "build.h"

namespace avdecc_lib
{
    class entity_descriptor;
    class descriptor_base;

    class end_station
    {
    public:
        /**
         * \return The status of the End Station connection.
         *	       'C' if connected. An End Station is connected after capturing an ADP packet with a different and unique Entity ID.
         *         'D' if disconnected. An End Station is disconnected after it fails to advertise through ADP for 62,000 milliseconds.
         */
        AVDECC_CONTROLLER_LIB32_API virtual const char STDCALL get_connection_status() const = 0;

        /**
         * \return The Entity ID of the End Station.
         */
        AVDECC_CONTROLLER_LIB32_API virtual uint64_t STDCALL entity_id() = 0;

        /**
         * \return The source MAC address of the End Station.
         */
        AVDECC_CONTROLLER_LIB32_API virtual uint64_t STDCALL mac() = 0;

        /**
         * \return The number of Entity descriptors for this End Station.
         */
        AVDECC_CONTROLLER_LIB32_API virtual size_t STDCALL entity_desc_count() = 0;

        /**
         * \return The corresponding ENTITY descriptor by index.
         */
        AVDECC_CONTROLLER_LIB32_API virtual entity_descriptor * STDCALL get_entity_desc_by_index(size_t entity_desc_index) = 0;

        /**
         * Send a READ_DESCRIPTOR command to read a descriptor from an AVDECC Entity. Reading a descriptor can be performed
         * by any AVDECC Controller even when the AVDECC Entitys locked or acquired as the act of reading the descriptor
         * does not affect the AVDECC Entity state.
         *
         * \param notification_id A void pointer to the unique identifier associated with the command.
         * \param desc_type The type of the descriptor to be read by the command.
         * \param desc_index The index of the descriptor to be read by the command.
         */
        AVDECC_CONTROLLER_LIB32_API virtual int STDCALL send_read_desc_cmd(void *notification_id, uint16_t desc_type, uint16_t desc_index) = 0;

        /**
         * Send a ENTITY_AVAILABLE command to verify that an AVDECC Entity is still available and responding to commands.
         *
         * \param notification_id A void pointer to the unique identifier associated with the command.
         */
        AVDECC_CONTROLLER_LIB32_API virtual int STDCALL send_entity_avail_cmd(void *notification_id) = 0;

        AVDECC_CONTROLLER_LIB32_API virtual int STDCALL send_aecp_address_access_cmd(void *notification_id,
                                                                                    unsigned mode,
                                                                                    unsigned length,
                                                                                    uint64_t address,
                                                                                    uint8_t memory_data[]) = 0;

        /**
         * Send a IDENTIFY command
         *
         * \param notification_id A void pointer to the unique identifier associated with the command.
         * \param turn_on When true the end station will be told to enable identification.
         */
        AVDECC_CONTROLLER_LIB32_API virtual int STDCALL send_identify(void *notification_id, bool turn_on) = 0;

        /**
         * \param entity_index The index of the entity to set as current selected.
         */
        AVDECC_CONTROLLER_LIB32_API virtual void STDCALL set_current_entity_index(uint16_t entity_index) = 0;


        /**
         * \return The index of the currently selected entity.
         */
        AVDECC_CONTROLLER_LIB32_API virtual uint16_t STDCALL get_current_entity_index() const = 0;

        /**
         * \param config_index The index of the config to set as current selected.
         */
        AVDECC_CONTROLLER_LIB32_API virtual void STDCALL set_current_config_index(uint16_t entity_index) = 0;

        /**
         * \return The index of the currently selected config.
         */
        AVDECC_CONTROLLER_LIB32_API virtual uint16_t STDCALL get_current_config_index() const = 0;
        
        /**
         * Send a REGISTER_UNSOLICITED_NOTIFICATION command to add the controller as being interested
         * in receiving unsolicited response notifications
         *
         * \param notification_id A void pointer to the unique identifier associated with the command.
         */
        AVDECC_CONTROLLER_LIB32_API virtual int STDCALL send_register_unsolicited_cmd(void *notification_id) = 0;
        
        /**
         * Send a DEREGISTER_UNSOLICITED_NOTIFICATION command to remove the controller as being interested
         * in receiving unsolicited response notifications
         *
         * \param notification_id A void pointer to the unique identifier associated with the command.
         */
        AVDECC_CONTROLLER_LIB32_API virtual int STDCALL send_deregister_unsolicited_cmd(void *notification_id) = 0;
    };
}

