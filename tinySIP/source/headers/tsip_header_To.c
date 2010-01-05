
/* #line 1 "tsip_parser_header_To.rl" */
/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_header_To.c
 * @brief SIP To/t header.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinysip/headers/tsip_header_To.h"

#include "tinysip/parsers/tsip_parser_uri.h"

#include "tsk_debug.h"
#include "tsk_memory.h"

/**@defgroup tsip_header_To_group SIP To header.
*/

/***********************************
*	Ragel state machine.
*/

/* #line 97 "tsip_parser_header_To.rl" */


int tsip_header_To_tostring(const void* header, tsk_buffer_t* output)
{
	if(header)
	{
		int ret;
		const tsip_header_To_t *To = header;
		if(ret=tsip_uri_tostring(To->uri, 1, 1, output))
		{
			return ret;
		}
		if(To->tag)
		{
			tsk_buffer_appendEx(output, ";tag=%s", To->tag);
		}
	}
	return -1;
}

tsip_header_To_t *tsip_header_To_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsip_header_To_t *hdr_to = TSIP_HEADER_TO_CREATE(0,0,0);
	
	const char *tag_start;

	
/* #line 79 "../source/headers/tsip_header_To.c" */
static const char _tsip_machine_parser_header_To_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 2, 1, 3, 
	2, 1, 4
};

static const short _tsip_machine_parser_header_To_key_offsets[] = {
	0, 0, 2, 7, 10, 31, 32, 34, 
	55, 56, 58, 61, 65, 77, 80, 80, 
	81, 85, 86, 105, 106, 108, 126, 145, 
	150, 151, 153, 157, 176, 177, 179, 198, 
	199, 201, 204, 220, 222, 224, 226, 228, 
	230, 231, 233, 237, 241, 242, 244, 247, 
	253, 271, 278, 286, 294, 302, 304, 311, 
	320, 322, 325, 327, 330, 332, 335, 338, 
	339, 342, 343, 346, 347, 356, 365, 373, 
	381, 389, 397, 399, 405, 414, 423, 432, 
	434, 437, 440, 441, 442, 444, 446, 450, 
	451, 453, 456, 473, 474, 476, 492, 510, 
	527, 545, 549, 550, 552, 568, 570, 572, 
	574, 576, 578, 579, 581, 585, 591, 611, 
	630, 635, 635, 639, 659, 678, 683, 703, 
	721, 739, 745, 751, 757, 763, 769, 773, 
	811, 848, 867, 904, 940, 948, 966, 997, 
	1029, 1061, 1093, 1113, 1144, 1177, 1199, 1222, 
	1244, 1267, 1289, 1312, 1335, 1354, 1377, 1396, 
	1419, 1438, 1471, 1504, 1536, 1568, 1600, 1632, 
	1652, 1682, 1715, 1748, 1781, 1803, 1826, 1849, 
	1868, 1887, 1907, 1927, 1946, 1982, 2018, 2029, 
	2041, 2053, 2065, 2071, 2082, 2095, 2101, 2108, 
	2114, 2121, 2127, 2134, 2141, 2146, 2153, 2158, 
	2165, 2170, 2183, 2196, 2208, 2220, 2232, 2244, 
	2250, 2260, 2273, 2286, 2299, 2305, 2312, 2319, 
	2324, 2329, 2335, 2341, 2346, 2364, 2382
};

static const char _tsip_machine_parser_header_To_trans_keys[] = {
	84, 116, 9, 32, 58, 79, 111, 9, 
	32, 58, 9, 13, 32, 33, 34, 37, 
	39, 60, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 96, 97, 122, 10, 
	9, 32, 9, 13, 32, 33, 34, 37, 
	39, 60, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 96, 97, 122, 10, 
	9, 32, 9, 32, 60, 65, 90, 97, 
	122, 9, 32, 43, 58, 45, 46, 48, 
	57, 65, 90, 97, 122, 9, 32, 58, 
	62, 9, 13, 32, 59, 10, 9, 13, 
	32, 33, 37, 39, 84, 116, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 10, 9, 32, 9, 32, 33, 37, 
	39, 84, 116, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 33, 37, 39, 59, 61, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 59, 61, 10, 9, 
	32, 9, 32, 59, 61, 9, 13, 32, 
	33, 34, 37, 39, 91, 126, 42, 43, 
	45, 46, 48, 57, 65, 90, 95, 122, 
	10, 9, 32, 9, 13, 32, 33, 34, 
	37, 39, 91, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 10, 9, 
	32, 9, 32, 34, 9, 13, 34, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 32, 126, -128, -65, -128, -65, 
	-128, -65, -128, -65, -128, -65, 10, 9, 
	32, 9, 13, 32, 59, 9, 13, 32, 
	59, 10, 9, 32, 9, 32, 59, 0, 
	9, 11, 12, 14, 127, 9, 13, 32, 
	33, 37, 39, 59, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 58, 
	48, 57, 65, 70, 97, 102, 58, 93, 
	48, 57, 65, 70, 97, 102, 58, 93, 
	48, 57, 65, 70, 97, 102, 58, 93, 
	48, 57, 65, 70, 97, 102, 58, 93, 
	58, 48, 57, 65, 70, 97, 102, 46, 
	58, 93, 48, 57, 65, 70, 97, 102, 
	48, 57, 46, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 93, 48, 57, 93, 
	48, 57, 93, 46, 48, 57, 46, 46, 
	48, 57, 46, 46, 58, 93, 48, 57, 
	65, 70, 97, 102, 46, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 46, 58, 93, 
	48, 57, 65, 70, 97, 102, 46, 58, 
	93, 48, 57, 65, 70, 97, 102, 46, 
	58, 93, 48, 57, 65, 70, 97, 102, 
	48, 57, 46, 48, 57, 46, 48, 57, 
	46, 58, 65, 97, 71, 103, 9, 13, 
	32, 61, 10, 9, 32, 9, 32, 61, 
	9, 13, 32, 33, 37, 39, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 10, 9, 32, 9, 32, 33, 37, 
	39, 126, 42, 43, 45, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 33, 
	37, 39, 59, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 33, 37, 39, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 37, 39, 60, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 60, 10, 9, 32, 
	9, 13, 34, 92, -64, -33, -32, -17, 
	-16, -9, -8, -5, -4, -3, 32, 126, 
	-128, -65, -128, -65, -128, -65, -128, -65, 
	-128, -65, 10, 9, 32, 9, 13, 32, 
	60, 0, 9, 11, 12, 14, 127, 9, 
	13, 32, 33, 37, 39, 42, 43, 58, 
	126, 45, 46, 48, 57, 65, 90, 95, 
	96, 97, 122, 9, 13, 32, 33, 37, 
	39, 58, 60, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 58, 60, 9, 13, 32, 59, 9, 
	13, 32, 33, 37, 39, 59, 84, 116, 
	126, 42, 43, 45, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 33, 37, 
	39, 59, 61, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 59, 61, 9, 13, 32, 33, 34, 
	37, 39, 59, 91, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 37, 39, 59, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 34, 59, 92, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 126, 9, 13, 32, 59, -128, 
	-65, 9, 13, 32, 59, -128, -65, 9, 
	13, 32, 59, -128, -65, 9, 13, 32, 
	59, -128, -65, 9, 13, 32, 59, -128, 
	-65, 9, 13, 32, 59, 9, 13, 32, 
	33, 34, 37, 39, 44, 47, 59, 84, 
	92, 116, 126, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 35, 41, 42, 
	57, 58, 64, 65, 90, 91, 94, 95, 
	122, 123, 125, 9, 13, 32, 33, 34, 
	37, 39, 44, 47, 59, 61, 92, 126, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 35, 41, 42, 57, 58, 64, 
	65, 90, 91, 94, 95, 122, 123, 125, 
	9, 13, 32, 34, 59, 61, 92, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 126, 9, 13, 32, 33, 34, 
	37, 39, 44, 47, 59, 91, 92, 126, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 35, 41, 42, 57, 58, 64, 
	65, 90, 93, 94, 95, 122, 123, 125, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	47, 59, 92, 126, -64, -33, -32, -17, 
	-16, -9, -8, -5, -4, -3, 35, 41, 
	42, 57, 58, 64, 65, 90, 91, 94, 
	95, 122, 123, 125, 9, 13, 32, 59, 
	0, 8, 11, 127, 9, 13, 32, 34, 
	59, 92, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 33, 126, 9, 13, 
	32, 34, 58, 59, 92, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	126, 9, 13, 32, 34, 58, 59, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 46, 58, 59, 92, 
	93, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 47, 48, 57, 60, 
	64, 65, 70, 71, 96, 97, 102, 103, 
	126, 9, 13, 32, 34, 59, 92, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 47, 48, 57, 58, 126, 9, 
	13, 32, 34, 46, 59, 92, -64, -33, 
	-32, -17, -16, -9, -8, -5, -4, -3, 
	33, 47, 48, 57, 58, 126, 9, 13, 
	32, 34, 59, 92, -64, -33, -32, -17, 
	-16, -9, -8, -5, -4, -3, 33, 47, 
	48, 57, 58, 126, 9, 13, 32, 34, 
	46, 59, 92, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 47, 48, 
	57, 58, 126, 9, 13, 32, 34, 59, 
	92, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 47, 48, 57, 58, 
	126, 9, 13, 32, 34, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 58, 126, 
	9, 13, 32, 34, 59, 92, 93, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 47, 48, 57, 58, 126, 9, 
	13, 32, 34, 59, 92, 93, -64, -33, 
	-32, -17, -16, -9, -8, -5, -4, -3, 
	33, 126, 9, 13, 32, 34, 46, 59, 
	92, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 47, 48, 57, 58, 
	126, 9, 13, 32, 34, 46, 59, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 126, 9, 13, 32, 34, 
	46, 59, 92, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 47, 48, 
	57, 58, 126, 9, 13, 32, 34, 46, 
	59, 92, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 33, 126, 9, 13, 
	32, 34, 46, 58, 59, 92, 93, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 47, 48, 57, 60, 64, 65, 
	70, 71, 96, 97, 102, 103, 126, 9, 
	13, 32, 34, 46, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 126, 9, 13, 32, 34, 
	59, 92, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 33, 47, 48, 57, 
	58, 64, 65, 70, 71, 96, 97, 102, 
	103, 126, 9, 13, 32, 34, 46, 58, 
	59, 92, 93, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 47, 48, 
	57, 60, 64, 65, 70, 71, 96, 97, 
	102, 103, 126, 9, 13, 32, 34, 46, 
	58, 59, 92, 93, -64, -33, -32, -17, 
	-16, -9, -8, -5, -4, -3, 33, 47, 
	48, 57, 60, 64, 65, 70, 71, 96, 
	97, 102, 103, 126, 9, 13, 32, 34, 
	46, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 59, 92, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 47, 48, 
	57, 58, 126, 9, 13, 32, 34, 46, 
	59, 92, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 33, 47, 48, 57, 
	58, 126, 9, 13, 32, 34, 46, 59, 
	92, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 47, 48, 57, 58, 
	126, 9, 13, 32, 34, 46, 59, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 126, 9, 13, 32, 34, 
	58, 59, 92, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 126, 9, 
	13, 32, 34, 59, 65, 92, 97, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 126, 9, 13, 32, 34, 59, 
	71, 92, 103, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 126, 9, 
	13, 32, 34, 59, 61, 92, -64, -33, 
	-32, -17, -16, -9, -8, -5, -4, -3, 
	33, 126, 9, 13, 32, 33, 34, 37, 
	39, 44, 47, 59, 92, 126, -64, -33, 
	-32, -17, -16, -9, -8, -5, -4, -3, 
	35, 41, 42, 57, 58, 64, 65, 90, 
	91, 94, 95, 122, 123, 125, 9, 13, 
	32, 33, 34, 37, 39, 44, 47, 59, 
	92, 126, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 35, 41, 42, 57, 
	58, 64, 65, 90, 91, 94, 95, 122, 
	123, 125, 9, 13, 32, 58, 59, 48, 
	57, 65, 70, 97, 102, 9, 13, 32, 
	58, 59, 93, 48, 57, 65, 70, 97, 
	102, 9, 13, 32, 58, 59, 93, 48, 
	57, 65, 70, 97, 102, 9, 13, 32, 
	58, 59, 93, 48, 57, 65, 70, 97, 
	102, 9, 13, 32, 58, 59, 93, 9, 
	13, 32, 58, 59, 48, 57, 65, 70, 
	97, 102, 9, 13, 32, 46, 58, 59, 
	93, 48, 57, 65, 70, 97, 102, 9, 
	13, 32, 59, 48, 57, 9, 13, 32, 
	46, 59, 48, 57, 9, 13, 32, 59, 
	48, 57, 9, 13, 32, 46, 59, 48, 
	57, 9, 13, 32, 59, 48, 57, 9, 
	13, 32, 59, 93, 48, 57, 9, 13, 
	32, 59, 93, 48, 57, 9, 13, 32, 
	59, 93, 9, 13, 32, 46, 59, 48, 
	57, 9, 13, 32, 46, 59, 9, 13, 
	32, 46, 59, 48, 57, 9, 13, 32, 
	46, 59, 9, 13, 32, 46, 58, 59, 
	93, 48, 57, 65, 70, 97, 102, 9, 
	13, 32, 46, 58, 59, 93, 48, 57, 
	65, 70, 97, 102, 9, 13, 32, 58, 
	59, 93, 48, 57, 65, 70, 97, 102, 
	9, 13, 32, 58, 59, 93, 48, 57, 
	65, 70, 97, 102, 9, 13, 32, 58, 
	59, 93, 48, 57, 65, 70, 97, 102, 
	9, 13, 32, 58, 59, 93, 48, 57, 
	65, 70, 97, 102, 9, 13, 32, 58, 
	59, 93, 9, 13, 32, 59, 48, 57, 
	65, 70, 97, 102, 9, 13, 32, 46, 
	58, 59, 93, 48, 57, 65, 70, 97, 
	102, 9, 13, 32, 46, 58, 59, 93, 
	48, 57, 65, 70, 97, 102, 9, 13, 
	32, 46, 58, 59, 93, 48, 57, 65, 
	70, 97, 102, 9, 13, 32, 59, 48, 
	57, 9, 13, 32, 46, 59, 48, 57, 
	9, 13, 32, 46, 59, 48, 57, 9, 
	13, 32, 46, 59, 9, 13, 32, 58, 
	59, 9, 13, 32, 59, 65, 97, 9, 
	13, 32, 59, 71, 103, 9, 13, 32, 
	59, 61, 9, 13, 32, 33, 37, 39, 
	59, 126, 42, 43, 45, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 33, 
	37, 39, 59, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 0
};

static const char _tsip_machine_parser_header_To_single_lengths[] = {
	0, 2, 5, 3, 9, 1, 2, 9, 
	1, 2, 3, 0, 4, 3, 0, 1, 
	4, 1, 9, 1, 2, 8, 9, 5, 
	1, 2, 4, 9, 1, 2, 9, 1, 
	2, 3, 4, 0, 0, 0, 0, 0, 
	1, 2, 4, 4, 1, 2, 3, 0, 
	8, 1, 2, 2, 2, 2, 1, 3, 
	0, 1, 0, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 3, 3, 2, 2, 
	2, 2, 2, 0, 3, 3, 3, 0, 
	1, 1, 1, 1, 2, 2, 4, 1, 
	2, 3, 7, 1, 2, 6, 8, 7, 
	8, 4, 1, 2, 4, 0, 0, 0, 
	0, 0, 1, 2, 4, 0, 10, 9, 
	5, 0, 4, 10, 9, 5, 10, 8, 
	6, 4, 4, 4, 4, 4, 4, 14, 
	13, 7, 13, 12, 4, 6, 7, 8, 
	8, 8, 8, 7, 9, 6, 7, 6, 
	7, 6, 7, 7, 7, 7, 7, 7, 
	7, 9, 9, 8, 8, 8, 8, 8, 
	6, 9, 9, 9, 6, 7, 7, 7, 
	7, 8, 8, 7, 12, 12, 5, 6, 
	6, 6, 6, 5, 7, 4, 5, 4, 
	5, 4, 5, 5, 5, 5, 5, 5, 
	5, 7, 7, 6, 6, 6, 6, 6, 
	4, 7, 7, 7, 4, 5, 5, 5, 
	5, 6, 6, 5, 8, 8, 0
};

static const char _tsip_machine_parser_header_To_range_lengths[] = {
	0, 0, 0, 0, 6, 0, 0, 6, 
	0, 0, 0, 2, 4, 0, 0, 0, 
	0, 0, 5, 0, 0, 5, 5, 0, 
	0, 0, 0, 5, 0, 0, 5, 0, 
	0, 0, 6, 1, 1, 1, 1, 1, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	5, 3, 3, 3, 3, 0, 3, 3, 
	1, 1, 1, 1, 1, 1, 1, 0, 
	1, 0, 1, 0, 3, 3, 3, 3, 
	3, 3, 0, 3, 3, 3, 3, 1, 
	1, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 5, 0, 0, 5, 5, 5, 
	5, 0, 0, 0, 6, 1, 1, 1, 
	1, 1, 0, 0, 0, 3, 5, 5, 
	0, 0, 0, 5, 5, 0, 5, 5, 
	6, 1, 1, 1, 1, 1, 0, 12, 
	12, 6, 12, 12, 2, 6, 12, 12, 
	12, 12, 6, 12, 12, 8, 8, 8, 
	8, 8, 8, 8, 6, 8, 6, 8, 
	6, 12, 12, 12, 12, 12, 12, 6, 
	12, 12, 12, 12, 8, 8, 8, 6, 
	6, 6, 6, 6, 12, 12, 3, 3, 
	3, 3, 0, 3, 3, 1, 1, 1, 
	1, 1, 1, 1, 0, 1, 0, 1, 
	0, 3, 3, 3, 3, 3, 3, 0, 
	3, 3, 3, 3, 1, 1, 1, 0, 
	0, 0, 0, 0, 5, 5, 0
};

static const short _tsip_machine_parser_header_To_index_offsets[] = {
	0, 0, 3, 9, 13, 29, 31, 34, 
	50, 52, 55, 59, 62, 71, 75, 76, 
	78, 83, 85, 100, 102, 105, 119, 134, 
	140, 142, 145, 150, 165, 167, 170, 185, 
	187, 190, 194, 205, 207, 209, 211, 213, 
	215, 217, 220, 225, 230, 232, 235, 239, 
	243, 257, 262, 268, 274, 280, 283, 288, 
	295, 297, 300, 302, 305, 307, 310, 313, 
	315, 318, 320, 323, 325, 332, 339, 345, 
	351, 357, 363, 366, 370, 377, 384, 391, 
	393, 396, 399, 401, 403, 406, 409, 414, 
	416, 419, 423, 436, 438, 441, 453, 467, 
	480, 494, 499, 501, 504, 515, 517, 519, 
	521, 523, 525, 527, 530, 535, 539, 555, 
	570, 576, 577, 582, 598, 613, 619, 635, 
	649, 662, 668, 674, 680, 686, 692, 697, 
	724, 750, 764, 790, 815, 822, 835, 855, 
	876, 897, 918, 933, 953, 975, 990, 1006, 
	1021, 1037, 1052, 1068, 1084, 1098, 1114, 1128, 
	1144, 1158, 1180, 1202, 1223, 1244, 1265, 1286, 
	1301, 1320, 1342, 1364, 1386, 1401, 1417, 1433, 
	1447, 1461, 1476, 1491, 1505, 1530, 1555, 1564, 
	1574, 1584, 1594, 1601, 1610, 1621, 1627, 1634, 
	1640, 1647, 1653, 1660, 1667, 1673, 1680, 1686, 
	1693, 1699, 1710, 1721, 1731, 1741, 1751, 1761, 
	1768, 1776, 1787, 1798, 1809, 1815, 1822, 1829, 
	1835, 1841, 1848, 1855, 1861, 1875, 1889
};

static const unsigned char _tsip_machine_parser_header_To_trans_targs[] = {
	2, 2, 0, 3, 3, 4, 3, 3, 
	0, 3, 3, 4, 0, 4, 5, 4, 
	95, 100, 95, 95, 11, 95, 95, 95, 
	95, 110, 95, 110, 0, 6, 0, 7, 
	7, 0, 7, 8, 7, 95, 100, 95, 
	95, 11, 95, 95, 95, 95, 110, 95, 
	110, 0, 9, 0, 10, 10, 0, 10, 
	10, 11, 0, 12, 12, 0, 13, 13, 
	12, 14, 12, 12, 12, 12, 0, 13, 
	13, 14, 0, 15, 16, 15, 16, 17, 
	16, 18, 0, 214, 0, 18, 19, 18, 
	22, 22, 22, 84, 84, 22, 22, 22, 
	22, 22, 22, 0, 20, 0, 21, 21, 
	0, 21, 21, 22, 22, 22, 84, 84, 
	22, 22, 22, 22, 22, 22, 0, 23, 
	17, 23, 22, 22, 22, 18, 27, 22, 
	22, 22, 22, 22, 22, 0, 23, 24, 
	23, 18, 27, 0, 25, 0, 26, 26, 
	0, 26, 26, 18, 27, 0, 27, 28, 
	27, 48, 34, 48, 48, 49, 48, 48, 
	48, 48, 48, 48, 0, 29, 0, 30, 
	30, 0, 30, 31, 30, 48, 34, 48, 
	48, 49, 48, 48, 48, 48, 48, 48, 
	0, 32, 0, 33, 33, 0, 33, 33, 
	34, 0, 34, 40, 42, 47, 35, 36, 
	37, 38, 39, 34, 0, 34, 0, 35, 
	0, 36, 0, 37, 0, 38, 0, 41, 
	0, 34, 34, 0, 43, 17, 43, 18, 
	0, 43, 44, 43, 18, 0, 45, 0, 
	46, 46, 0, 46, 46, 18, 0, 34, 
	34, 34, 0, 43, 17, 43, 48, 48, 
	48, 18, 48, 48, 48, 48, 48, 48, 
	0, 83, 50, 50, 50, 0, 54, 42, 
	51, 51, 51, 0, 54, 42, 52, 52, 
	52, 0, 54, 42, 53, 53, 53, 0, 
	54, 42, 0, 70, 55, 50, 50, 0, 
	56, 54, 42, 68, 51, 51, 0, 57, 
	0, 58, 66, 0, 59, 0, 60, 64, 
	0, 61, 0, 42, 62, 0, 42, 63, 
	0, 42, 0, 60, 65, 0, 60, 0, 
	58, 67, 0, 58, 0, 56, 54, 42, 
	69, 52, 52, 0, 56, 54, 42, 53, 
	53, 53, 0, 79, 42, 71, 71, 71, 
	0, 75, 42, 72, 72, 72, 0, 75, 
	42, 73, 73, 73, 0, 75, 42, 74, 
	74, 74, 0, 75, 42, 0, 76, 71, 
	71, 0, 56, 75, 42, 77, 72, 72, 
	0, 56, 75, 42, 78, 73, 73, 0, 
	56, 75, 42, 74, 74, 74, 0, 80, 
	0, 56, 81, 0, 56, 82, 0, 56, 
	0, 70, 0, 85, 85, 0, 86, 86, 
	0, 86, 87, 86, 90, 0, 88, 0, 
	89, 89, 0, 89, 89, 90, 0, 90, 
	91, 90, 94, 94, 94, 94, 94, 94, 
	94, 94, 94, 0, 92, 0, 93, 93, 
	0, 93, 93, 94, 94, 94, 94, 94, 
	94, 94, 94, 94, 0, 43, 17, 43, 
	94, 94, 94, 18, 94, 94, 94, 94, 
	94, 94, 0, 96, 98, 96, 95, 95, 
	95, 95, 95, 95, 95, 95, 95, 0, 
	97, 8, 97, 95, 95, 95, 11, 95, 
	95, 95, 95, 95, 95, 0, 97, 8, 
	97, 11, 0, 99, 0, 96, 96, 0, 
	100, 106, 108, 109, 101, 102, 103, 104, 
	105, 100, 0, 100, 0, 101, 0, 102, 
	0, 103, 0, 104, 0, 107, 0, 100, 
	100, 0, 97, 8, 97, 11, 0, 100, 
	100, 100, 0, 111, 98, 111, 95, 95, 
	95, 95, 110, 113, 95, 110, 110, 110, 
	95, 110, 0, 112, 8, 112, 95, 95, 
	95, 113, 11, 95, 95, 95, 95, 95, 
	95, 0, 112, 8, 112, 113, 11, 0, 
	114, 114, 17, 114, 115, 114, 115, 17, 
	115, 116, 116, 116, 115, 209, 209, 116, 
	116, 116, 116, 116, 116, 114, 117, 17, 
	117, 116, 116, 116, 115, 118, 116, 116, 
	116, 116, 116, 116, 114, 117, 17, 117, 
	115, 118, 114, 118, 17, 118, 119, 120, 
	119, 119, 115, 174, 119, 119, 119, 119, 
	119, 119, 114, 114, 17, 114, 119, 119, 
	119, 115, 119, 119, 119, 119, 119, 119, 
	114, 120, 17, 120, 126, 127, 132, 121, 
	122, 123, 124, 125, 120, 114, 114, 17, 
	114, 115, 120, 114, 114, 17, 114, 115, 
	121, 114, 114, 17, 114, 115, 122, 114, 
	114, 17, 114, 115, 123, 114, 114, 17, 
	114, 115, 124, 114, 114, 17, 114, 115, 
	114, 127, 17, 127, 128, 126, 128, 128, 
	120, 120, 127, 169, 132, 169, 128, 121, 
	122, 123, 124, 125, 120, 128, 120, 128, 
	120, 128, 120, 114, 129, 17, 129, 128, 
	126, 128, 128, 120, 120, 127, 130, 132, 
	128, 121, 122, 123, 124, 125, 120, 128, 
	120, 128, 120, 128, 120, 114, 129, 17, 
	129, 126, 127, 130, 132, 121, 122, 123, 
	124, 125, 120, 114, 130, 17, 130, 131, 
	133, 131, 131, 120, 120, 127, 134, 132, 
	131, 121, 122, 123, 124, 125, 120, 131, 
	120, 131, 120, 131, 120, 114, 120, 17, 
	120, 131, 126, 131, 131, 120, 120, 127, 
	132, 131, 121, 122, 123, 124, 125, 120, 
	131, 120, 131, 120, 131, 120, 114, 120, 
	17, 120, 127, 120, 120, 114, 120, 17, 
	120, 126, 127, 132, 121, 122, 123, 124, 
	125, 120, 114, 120, 17, 120, 126, 168, 
	127, 132, 121, 122, 123, 124, 125, 120, 
	135, 120, 135, 120, 135, 120, 114, 120, 
	17, 120, 126, 139, 127, 132, 133, 121, 
	122, 123, 124, 125, 120, 136, 120, 136, 
	120, 136, 120, 114, 120, 17, 120, 126, 
	139, 127, 132, 133, 121, 122, 123, 124, 
	125, 120, 137, 120, 137, 120, 137, 120, 
	114, 120, 17, 120, 126, 139, 127, 132, 
	133, 121, 122, 123, 124, 125, 120, 138, 
	120, 138, 120, 138, 120, 114, 120, 17, 
	120, 126, 139, 127, 132, 133, 121, 122, 
	123, 124, 125, 120, 114, 120, 17, 120, 
	126, 155, 127, 132, 121, 122, 123, 124, 
	125, 120, 140, 120, 135, 120, 135, 120, 
	114, 120, 17, 120, 126, 141, 139, 127, 
	132, 133, 121, 122, 123, 124, 125, 120, 
	153, 120, 136, 120, 136, 120, 114, 120, 
	17, 120, 126, 127, 132, 121, 122, 123, 
	124, 125, 120, 142, 120, 114, 120, 17, 
	120, 126, 143, 127, 132, 121, 122, 123, 
	124, 125, 120, 151, 120, 114, 120, 17, 
	120, 126, 127, 132, 121, 122, 123, 124, 
	125, 120, 144, 120, 114, 120, 17, 120, 
	126, 145, 127, 132, 121, 122, 123, 124, 
	125, 120, 149, 120, 114, 120, 17, 120, 
	126, 127, 132, 121, 122, 123, 124, 125, 
	120, 146, 120, 114, 120, 17, 120, 126, 
	127, 132, 133, 121, 122, 123, 124, 125, 
	120, 147, 120, 114, 120, 17, 120, 126, 
	127, 132, 133, 121, 122, 123, 124, 125, 
	120, 148, 120, 114, 120, 17, 120, 126, 
	127, 132, 133, 121, 122, 123, 124, 125, 
	120, 114, 120, 17, 120, 126, 145, 127, 
	132, 121, 122, 123, 124, 125, 120, 150, 
	120, 114, 120, 17, 120, 126, 145, 127, 
	132, 121, 122, 123, 124, 125, 120, 114, 
	120, 17, 120, 126, 143, 127, 132, 121, 
	122, 123, 124, 125, 120, 152, 120, 114, 
	120, 17, 120, 126, 143, 127, 132, 121, 
	122, 123, 124, 125, 120, 114, 120, 17, 
	120, 126, 141, 139, 127, 132, 133, 121, 
	122, 123, 124, 125, 120, 154, 120, 137, 
	120, 137, 120, 114, 120, 17, 120, 126, 
	141, 139, 127, 132, 133, 121, 122, 123, 
	124, 125, 120, 138, 120, 138, 120, 138, 
	120, 114, 120, 17, 120, 126, 164, 127, 
	132, 133, 121, 122, 123, 124, 125, 120, 
	156, 120, 156, 120, 156, 120, 114, 120, 
	17, 120, 126, 160, 127, 132, 133, 121, 
	122, 123, 124, 125, 120, 157, 120, 157, 
	120, 157, 120, 114, 120, 17, 120, 126, 
	160, 127, 132, 133, 121, 122, 123, 124, 
	125, 120, 158, 120, 158, 120, 158, 120, 
	114, 120, 17, 120, 126, 160, 127, 132, 
	133, 121, 122, 123, 124, 125, 120, 159, 
	120, 159, 120, 159, 120, 114, 120, 17, 
	120, 126, 160, 127, 132, 133, 121, 122, 
	123, 124, 125, 120, 114, 120, 17, 120, 
	126, 127, 132, 121, 122, 123, 124, 125, 
	120, 161, 120, 156, 120, 156, 120, 114, 
	120, 17, 120, 126, 141, 160, 127, 132, 
	133, 121, 122, 123, 124, 125, 120, 162, 
	120, 157, 120, 157, 120, 114, 120, 17, 
	120, 126, 141, 160, 127, 132, 133, 121, 
	122, 123, 124, 125, 120, 163, 120, 158, 
	120, 158, 120, 114, 120, 17, 120, 126, 
	141, 160, 127, 132, 133, 121, 122, 123, 
	124, 125, 120, 159, 120, 159, 120, 159, 
	120, 114, 120, 17, 120, 126, 127, 132, 
	121, 122, 123, 124, 125, 120, 165, 120, 
	114, 120, 17, 120, 126, 141, 127, 132, 
	121, 122, 123, 124, 125, 120, 166, 120, 
	114, 120, 17, 120, 126, 141, 127, 132, 
	121, 122, 123, 124, 125, 120, 167, 120, 
	114, 120, 17, 120, 126, 141, 127, 132, 
	121, 122, 123, 124, 125, 120, 114, 120, 
	17, 120, 126, 155, 127, 132, 121, 122, 
	123, 124, 125, 120, 114, 120, 17, 120, 
	126, 127, 170, 132, 170, 121, 122, 123, 
	124, 125, 120, 114, 120, 17, 120, 126, 
	127, 171, 132, 171, 121, 122, 123, 124, 
	125, 120, 114, 171, 17, 171, 126, 127, 
	172, 132, 121, 122, 123, 124, 125, 120, 
	114, 172, 17, 172, 173, 126, 173, 173, 
	120, 120, 127, 132, 173, 121, 122, 123, 
	124, 125, 120, 173, 120, 173, 120, 173, 
	120, 114, 120, 17, 120, 173, 126, 173, 
	173, 120, 120, 127, 132, 173, 121, 122, 
	123, 124, 125, 120, 173, 120, 173, 120, 
	173, 120, 114, 114, 17, 114, 208, 115, 
	175, 175, 175, 114, 114, 17, 114, 179, 
	115, 126, 176, 176, 176, 114, 114, 17, 
	114, 179, 115, 126, 177, 177, 177, 114, 
	114, 17, 114, 179, 115, 126, 178, 178, 
	178, 114, 114, 17, 114, 179, 115, 126, 
	114, 114, 17, 114, 195, 115, 180, 175, 
	175, 114, 114, 17, 114, 181, 179, 115, 
	126, 193, 176, 176, 114, 114, 17, 114, 
	115, 182, 114, 114, 17, 114, 183, 115, 
	191, 114, 114, 17, 114, 115, 184, 114, 
	114, 17, 114, 185, 115, 189, 114, 114, 
	17, 114, 115, 186, 114, 114, 17, 114, 
	115, 126, 187, 114, 114, 17, 114, 115, 
	126, 188, 114, 114, 17, 114, 115, 126, 
	114, 114, 17, 114, 185, 115, 190, 114, 
	114, 17, 114, 185, 115, 114, 114, 17, 
	114, 183, 115, 192, 114, 114, 17, 114, 
	183, 115, 114, 114, 17, 114, 181, 179, 
	115, 126, 194, 177, 177, 114, 114, 17, 
	114, 181, 179, 115, 126, 178, 178, 178, 
	114, 114, 17, 114, 204, 115, 126, 196, 
	196, 196, 114, 114, 17, 114, 200, 115, 
	126, 197, 197, 197, 114, 114, 17, 114, 
	200, 115, 126, 198, 198, 198, 114, 114, 
	17, 114, 200, 115, 126, 199, 199, 199, 
	114, 114, 17, 114, 200, 115, 126, 114, 
	114, 17, 114, 115, 201, 196, 196, 114, 
	114, 17, 114, 181, 200, 115, 126, 202, 
	197, 197, 114, 114, 17, 114, 181, 200, 
	115, 126, 203, 198, 198, 114, 114, 17, 
	114, 181, 200, 115, 126, 199, 199, 199, 
	114, 114, 17, 114, 115, 205, 114, 114, 
	17, 114, 181, 115, 206, 114, 114, 17, 
	114, 181, 115, 207, 114, 114, 17, 114, 
	181, 115, 114, 114, 17, 114, 195, 115, 
	114, 114, 17, 114, 115, 210, 210, 114, 
	114, 17, 114, 115, 211, 211, 114, 211, 
	17, 211, 115, 212, 114, 212, 17, 212, 
	213, 213, 213, 115, 213, 213, 213, 213, 
	213, 213, 114, 114, 17, 114, 213, 213, 
	213, 115, 213, 213, 213, 213, 213, 213, 
	114, 0, 0
};

static const char _tsip_machine_parser_header_To_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 11, 0, 0, 0, 0, 
	1, 1, 1, 0, 0, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 1, 0, 0, 
	1, 1, 1, 1, 1, 1, 0, 9, 
	9, 9, 0, 0, 0, 9, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 9, 9, 9, 9, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 9, 9, 9, 0, 0, 
	0, 9, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 7, 7, 7, 
	0, 0, 0, 7, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	5, 5, 5, 0, 0, 0, 5, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 5, 5, 5, 5, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 5, 5, 5, 0, 0, 
	0, 0, 5, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 3, 0, 3, 3, 
	3, 1, 1, 1, 3, 0, 0, 1, 
	1, 1, 1, 1, 1, 0, 16, 16, 
	16, 0, 0, 0, 16, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	3, 0, 0, 3, 3, 3, 0, 0, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 16, 16, 16, 0, 0, 
	0, 16, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 3, 0, 0, 3, 3, 3, 3, 
	0, 0, 3, 3, 3, 3, 0, 0, 
	3, 3, 3, 3, 0, 0, 3, 3, 
	3, 3, 0, 0, 16, 16, 16, 16, 
	0, 3, 3, 3, 1, 0, 1, 1, 
	0, 0, 3, 0, 0, 0, 1, 0, 
	0, 0, 0, 0, 0, 1, 0, 1, 
	0, 1, 0, 0, 16, 16, 16, 0, 
	0, 0, 0, 0, 0, 16, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 0, 0, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 16, 16, 
	16, 0, 0, 0, 0, 0, 0, 16, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 3, 0, 0, 0, 16, 16, 
	16, 0, 16, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 1, 0, 1, 1, 
	0, 0, 3, 0, 1, 0, 0, 0, 
	0, 0, 0, 1, 0, 1, 0, 1, 
	0, 0, 13, 13, 13, 0, 0, 0, 
	0, 0, 0, 13, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 3, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 3, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 3, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	3, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 3, 3, 3, 3, 0, 0, 
	3, 3, 3, 0, 3, 0, 0, 3, 
	3, 3, 3, 0, 0, 3, 3, 3, 
	3, 0, 0, 0, 3, 3, 3, 3, 
	0, 0, 0, 3, 3, 3, 3, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	3, 3, 3, 0, 3, 0, 3, 3, 
	3, 0, 3, 0, 0, 3, 3, 3, 
	0, 3, 0, 3, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 3, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 3, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	3, 3, 3, 3, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 3, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 3, 0, 0, 0, 0, 
	0, 3, 3, 3, 3, 0, 0, 3, 
	3, 3, 0, 3, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 3, 3, 3, 
	0, 3, 0, 3, 3, 3, 0, 3, 
	0, 3, 3, 3, 3, 0, 0, 0, 
	3, 3, 3, 3, 0, 0, 0, 3, 
	3, 3, 3, 0, 0, 3, 3, 3, 
	1, 1, 1, 3, 1, 1, 1, 1, 
	1, 1, 0, 13, 13, 13, 0, 0, 
	0, 13, 0, 0, 0, 0, 0, 0, 
	0, 0, 0
};

static const int tsip_machine_parser_header_To_start = 1;
static const int tsip_machine_parser_header_To_first_final = 214;
static const int tsip_machine_parser_header_To_error = 0;

static const int tsip_machine_parser_header_To_en_main = 1;


/* #line 128 "tsip_parser_header_To.rl" */
	
/* #line 996 "../source/headers/tsip_header_To.c" */
	{
	cs = tsip_machine_parser_header_To_start;
	}

/* #line 129 "tsip_parser_header_To.rl" */
	
/* #line 1003 "../source/headers/tsip_header_To.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _tsip_machine_parser_header_To_trans_keys + _tsip_machine_parser_header_To_key_offsets[cs];
	_trans = _tsip_machine_parser_header_To_index_offsets[cs];

	_klen = _tsip_machine_parser_header_To_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _tsip_machine_parser_header_To_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _tsip_machine_parser_header_To_trans_targs[_trans];

	if ( _tsip_machine_parser_header_To_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _tsip_machine_parser_header_To_actions + _tsip_machine_parser_header_To_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 50 "tsip_parser_header_To.rl" */
	{
		TSK_DEBUG_INFO("TO:TAG");
		tag_start = p;
	}
	break;
	case 1:
/* #line 56 "tsip_parser_header_To.rl" */
	{
		int len = (int)(p  - tag_start);
		hdr_to->uri = tsip_uri_parse(tag_start, (size_t)len);
		TSK_DEBUG_INFO("TO:PARSE_URI");
	}
	break;
	case 2:
/* #line 63 "tsip_parser_header_To.rl" */
	{
		PARSER_SET_STRING(hdr_to->display_name);
		TSK_DEBUG_INFO("TO:PARSE_DISPLAY_NAME");
	}
	break;
	case 3:
/* #line 69 "tsip_parser_header_To.rl" */
	{
		PARSER_SET_STRING(hdr_to->tag);
		TSK_DEBUG_INFO("TO:PARSE_TAG");
	}
	break;
	case 4:
/* #line 75 "tsip_parser_header_To.rl" */
	{
		PARSER_ADD_PARAM(TSIP_HEADER_PARAMS(hdr_to));
		TSK_DEBUG_INFO("TO:PARSE_PARAM");
	}
	break;
	case 5:
/* #line 81 "tsip_parser_header_To.rl" */
	{
		TSK_DEBUG_INFO("TO:EOB");
	}
	break;
/* #line 1118 "../source/headers/tsip_header_To.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

/* #line 130 "tsip_parser_header_To.rl" */
	
	if( cs < 
/* #line 1134 "../source/headers/tsip_header_To.c" */
214
/* #line 131 "tsip_parser_header_To.rl" */
 )
	{
		TSIP_HEADER_TO_SAFE_FREE(hdr_to);
	}
	
	return hdr_to;
}







//========================================================
//	To header object definition
//

/**@ingroup tsip_header_To_group
*/
static void* tsip_header_To_create(void *self, va_list * app)
{
	tsip_header_To_t *To = self;
	if(To)
	{
		const char* display_name = va_arg(*app, const char *);
		const tsip_uri_t* uri = va_arg(*app, const tsip_uri_t *);
		const char* tag = va_arg(*app, const char *);

		To->display_name = tsk_strdup(display_name);
		if(uri) To->uri = tsk_object_ref((void *)uri);
		To->tag = tsk_strdup(tag);

		TSIP_HEADER(To)->type = tsip_htype_To;
		TSIP_HEADER(To)->tostring = tsip_header_To_tostring;
	}
	else
	{
		TSK_DEBUG_ERROR("Failed to create new To header.");
	}
	return self;
}

/**@ingroup tsip_header_To_group
*/
static void* tsip_header_To_destroy(void *self)
{
	tsip_header_To_t *To = self;
	if(To)
	{
		TSK_FREE(To->display_name);
		TSK_FREE(To->tag);

		TSIP_URI_SAFE_FREE(To->uri);
		TSK_LIST_SAFE_FREE(TSIP_HEADER_PARAMS(To));
	}
	else TSK_DEBUG_ERROR("Null To header.");

	return self;
}

static const tsk_object_def_t tsip_header_To_def_s = 
{
	sizeof(tsip_header_To_t),
	tsip_header_To_create,
	tsip_header_To_destroy,
	0
};
const void *tsip_header_To_def_t = &tsip_header_To_def_s;