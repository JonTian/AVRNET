//********************************************************************************************
//
// File : _struct.h header for all structure
//
//********************************************************************************************
//
// Copyright (C) 2007
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
// This program is distributed in the hope that it will be useful, but
//
// WITHOUT ANY WARRANTY;
//
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
// PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin St, Fifth Floor, Boston, MA 02110, USA
//
// http://www.gnu.de/gpl-ger.html
//
//********************************************************************************************
//typedef enum _BOOL { false = 0, true } bool;
typedef unsigned char	BYTE;				// 8-bit
typedef unsigned int	WORD;				// 16-bit
typedef unsigned long	DWORD;				// 32-bit

typedef union _BYTE_BITS
{
    BYTE byte;
    struct
    {
        unsigned char bit0:1;
        unsigned char bit1:1;
        unsigned char bit2:1;
        unsigned char bit3:1;
        unsigned char bit4:1;
        unsigned char bit5:1;
        unsigned char bit6:1;
        unsigned char bit7:1;
    } bits;
} BYTE_BITS;

typedef union _WORD_BYTES
{
    WORD word;
    BYTE bytes[2];
    struct
    {
        BYTE low;
        BYTE high;
    } byte;
    struct
    {
        unsigned char bit0:1;
        unsigned char bit1:1;
        unsigned char bit2:1;
        unsigned char bit3:1;
        unsigned char bit4:1;
        unsigned char bit5:1;
        unsigned char bit6:1;
        unsigned char bit7:1;
        unsigned char bit8:1;
        unsigned char bit9:1;
        unsigned char bit10:1;
        unsigned char bit11:1;
        unsigned char bit12:1;
        unsigned char bit13:1;
        unsigned char bit14:1;
        unsigned char bit15:1;
    } bits;
} WORD_BYTES;

typedef union _DWORD_BYTE
{
    DWORD dword;
	WORD words[2];
    BYTE bytes[4];
    struct
    {
        WORD low;
        WORD high;
    } word;
    struct
    {
        BYTE LB;
        BYTE HB;
        BYTE UB;
        BYTE MB;
    } byte;
    struct
    {
        unsigned char bit0:1;
        unsigned char bit1:1;
        unsigned char bit2:1;
        unsigned char bit3:1;
        unsigned char bit4:1;
        unsigned char bit5:1;
        unsigned char bit6:1;
        unsigned char bit7:1;
        unsigned char bit8:1;
        unsigned char bit9:1;
        unsigned char bit10:1;
        unsigned char bit11:1;
        unsigned char bit12:1;
        unsigned char bit13:1;
        unsigned char bit14:1;
        unsigned char bit15:1;
        unsigned char bit16:1;
        unsigned char bit17:1;
        unsigned char bit18:1;
        unsigned char bit19:1;
        unsigned char bit20:1;
        unsigned char bit21:1;
        unsigned char bit22:1;
        unsigned char bit23:1;
        unsigned char bit24:1;
        unsigned char bit25:1;
        unsigned char bit26:1;
        unsigned char bit27:1;
        unsigned char bit28:1;
        unsigned char bit29:1;
        unsigned char bit30:1;
        unsigned char bit31:1;
    } bits;
} DWORD_BYTES;

// mac address structure
typedef struct _MAC_ADDR
{
    BYTE byte[6];
}MAC_ADDR;

// ethernet header structure
typedef struct _ETH_HEADER
{
	MAC_ADDR	dest_mac;
	MAC_ADDR	src_mac;
	WORD_BYTES	type;
}ETH_HEADER;

// IP address structure
typedef struct _IP_ADDR
{
	BYTE byte[4];
}IP_ADDR;

// IP header structure
typedef struct _IP_HEADER
{
	BYTE		version_hlen;
	BYTE		type_of_service;
	WORD_BYTES	total_length;
	WORD_BYTES	indentificaton;
	WORD_BYTES	flagment;
	BYTE		time_to_live;
	BYTE		protocol;
	WORD_BYTES	checksum;
	IP_ADDR		src_ip;
	IP_ADDR		dest_ip;

}IP_HEADER;

// ARP packet structure
typedef struct _ARP_PACKET
{
	WORD_BYTES	hardware_type;
	WORD_BYTES	protocol_type;
	BYTE		hardware_length;
	BYTE		protocol_length;
	WORD_BYTES	opcode;
	MAC_ADDR	src_mac;
	IP_ADDR		src_ip;
	MAC_ADDR	dest_mac;
	IP_ADDR		dest_ip;
} ARP_PACKET;

// ICMP packet structure
#define ICMP_MAX_DATA	32
typedef struct _ICMP_PACKET
{
	BYTE		type;
	BYTE		code;
	WORD_BYTES	checksum;
	WORD_BYTES	identifier;
	WORD_BYTES	sequence_number;
	BYTE		data[ICMP_MAX_DATA];
} ICMP_PACKET;

// TCP Header
typedef struct _TCP_HEADER
{
	WORD_BYTES	src_port;
	WORD_BYTES	dest_port;
	DWORD_BYTES	sequence_number;
	DWORD_BYTES	seqack_number;
	
	union
	{
		struct
		{
			unsigned char reserved:4;
			unsigned char value:4;			
		}nibble;
		unsigned char byte;
	}data_offset;

	union
	{
		struct
		{			
			unsigned char FIN:1;
			unsigned char SYN:1;
			unsigned char RST:1;
			unsigned char PSH:1;
			unsigned char ACK:1;
			unsigned char URG:1;
			unsigned char reserved:2;			
		} bits;
		unsigned char byte;
	} flags;
	WORD_BYTES	window;
	WORD_BYTES	checksum;
	WORD_BYTES	urgent_pointer;
} TCP_HEADER;

typedef struct _TCP_OPTION
{
	BYTE		kind;
	BYTE		length;
	WORD_BYTES	max_seg_size;
} TCP_OPTION;

typedef struct _UDP_HEADER
{
	WORD	src_port;
	WORD	dst_port;
	WORD	length;
	WORD	checksum;
} UDP_HEADER;

union flag1
{
	BYTE byte;
	struct
	{
		unsigned char key_is_executed:1;
		unsigned char update_display:1;
		unsigned char lcd_busy:1;
		unsigned char key_press:1;
		unsigned char send_temp:1;
		unsigned char syn_is_sent:1;
		unsigned char syn_is_received:1;
		unsigned char send_temp_timeout:1;
	}bits;
}flag1;

union flag2
{
	BYTE byte;
	struct
	{
		unsigned char key_hold:1;
		unsigned char software_reset:1;
		unsigned char unuse:6;
	}bits;
}flag2;
