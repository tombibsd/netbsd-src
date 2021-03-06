/*	$NetBSD$	*/

/*
 * Copyright (c) 2008 Kungliga Tekniska Högskolan
 * (Royal Institute of Technology, Stockholm, Sweden).
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <der_locl.h>
#include <krb5/rfc2459_asn1.h>
#include <krb5/cms_asn1.h>


__RCSID("NetBSD");

static const unsigned char *contentdata = (unsigned char *)
    "\x30\x80\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x07\x02\xa0\x80\x30"
    "\x80\x02\x01\x03\x31\x0b\x30\x09\x06\x05\x2b\x0e\x03\x02\x1a\x05"
    "\x00\x30\x80\x06\x07\x2b\x06\x01\x05\x02\x03\x01\xa0\x80\x24\x80"
    "\x04\x40\x30\x3e\xa0\x3c\x30\x3a\xa0\x05\x02\x03\x0e\x03\x86\xa1"
    "\x11\x18\x0f\x32\x30\x30\x38\x31\x32\x31\x33\x31\x39\x34\x35\x34"
    "\x32\x5a\xa2\x06\x02\x04\xba\xbd\x97\x8a\xa3\x16\x04\x14\x41\x28"
    "\x79\xa8\xd0\xe4\xb1\x0f\xb1\xfc\xa6\x0b\x4d\x2b\x85\x3d\xd9\x17"
    "\x3f\xdc\x00\x00\x00\x00\x00\x00\xa0\x82\x0b\x6c\x30\x82\x05\x57"
    "\x30\x82\x04\x3f\xa0\x03\x02\x01\x02\x02\x03\x47\x3d\x05\x30\x0d"
    "\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x05\x05\x00\x30\x81\x86"
    "\x31\x0b\x30\x09\x06\x03\x55\x04\x06\x13\x02\x55\x53\x31\x1d\x30"
    "\x1b\x06\x03\x55\x04\x0a\x13\x14\x41\x70\x70\x6c\x65\x20\x43\x6f"
    "\x6d\x70\x75\x74\x65\x72\x2c\x20\x49\x6e\x63\x2e\x31\x2d\x30\x2b"
    "\x06\x03\x55\x04\x0b\x13\x24\x41\x70\x70\x6c\x65\x20\x43\x6f\x6d"
    "\x70\x75\x74\x65\x72\x20\x43\x65\x72\x74\x69\x66\x69\x63\x61\x74"
    "\x65\x20\x41\x75\x74\x68\x6f\x72\x69\x74\x79\x31\x29\x30\x27\x06"
    "\x03\x55\x04\x03\x13\x20\x41\x70\x70\x6c\x65\x20\x2e\x4d\x61\x63"
    "\x20\x43\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x20\x41\x75\x74"
    "\x68\x6f\x72\x69\x74\x79\x30\x1e\x17\x0d\x30\x38\x31\x30\x30\x31"
    "\x30\x38\x30\x36\x33\x33\x5a\x17\x0d\x30\x39\x31\x30\x30\x32\x30"
    "\x38\x30\x36\x33\x33\x5a\x30\x71\x31\x0b\x30\x09\x06\x03\x55\x04"
    "\x06\x13\x02\x55\x53\x31\x13\x30\x11\x06\x03\x55\x04\x0a\x13\x0a"
    "\x41\x70\x70\x6c\x65\x20\x49\x6e\x63\x2e\x31\x0f\x30\x0d\x06\x03"
    "\x55\x04\x0b\x13\x06\x6d\x65\x2e\x63\x6f\x6d\x31\x15\x30\x13\x06"
    "\x03\x55\x04\x03\x13\x0c\x62\x69\x74\x63\x6f\x6c\x6c\x65\x63\x74"
    "\x6f\x72\x31\x25\x30\x23\x06\x03\x55\x04\x0d\x13\x1c\x4d\x6f\x62"
    "\x69\x6c\x65\x4d\x65\x20\x53\x68\x61\x72\x69\x6e\x67\x20\x43\x65"
    "\x72\x74\x69\x66\x69\x63\x61\x74\x65\x30\x81\xa3\x30\x0d\x06\x09"
    "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x01\x05\x00\x03\x81\x91\x00\x30"
    "\x81\x8d\x02\x81\x81\x00\xe1\x15\xd8\xfa\xe9\xc2\xb7\x2e\xf0\xd9"
    "\xbe\xdb\x0c\xd8\xcb\xf3\x88\x13\xd7\x22\xf8\x4d\xf4\xb6\x31\x17"
    "\xe5\x92\x42\xef\x15\xe4\x5f\x12\x58\x3d\x8d\x0b\xa4\x03\x76\xe0"
    "\xd0\xf2\x46\xb4\x4b\x14\x78\x23\x1c\x38\xb0\x99\xff\x36\x6f\x0e"
    "\x26\xdf\x76\xd0\x01\x03\x7a\xd9\xcd\x1c\x92\xa6\x10\x5e\xed\x8a"
    "\xb0\xfe\x9b\x8c\x96\xb0\x91\x9f\x97\xd0\xf4\x9c\x81\x8e\xbf\xb5"
    "\x41\x24\x81\xb0\x1b\xb3\x8c\xd3\x92\x5c\xfd\x2b\x04\x61\xc3\x21"
    "\x6c\xa9\xe4\xa0\xfe\xa5\x1c\x76\xfd\xda\x3b\x81\x7c\xa0\x5c\x2c"
    "\xf6\x8f\x6e\x74\x52\x35\x02\x07\x01\x00\x01\x00\x01\x00\x01\xa3"
    "\x82\x02\x60\x30\x82\x02\x5c\x30\x0c\x06\x03\x55\x1d\x13\x01\x01"
    "\xff\x04\x02\x30\x00\x30\x0e\x06\x03\x55\x1d\x0f\x01\x01\xff\x04"
    "\x04\x03\x02\x03\x88\x30\x28\x06\x03\x55\x1d\x25\x04\x21\x30\x1f"
    "\x06\x08\x2b\x06\x01\x05\x05\x07\x03\x02\x06\x0a\x2a\x86\x48\x86"
    "\xf7\x63\x64\x03\x02\x01\x06\x07\x2b\x06\x01\x05\x02\x03\x04\x30"
    "\x1d\x06\x03\x55\x1d\x0e\x04\x16\x04\x14\x11\xb3\x15\xb5\xab\x31"
    "\xbb\xa5\x48\xee\xd6\x33\xd2\x86\xc3\x0b\x2a\x4c\x5e\x94\x30\x1f"
    "\x06\x03\x55\x1d\x23\x04\x18\x30\x16\x80\x14\x7a\x7d\x90\xb1\x30"
    "\x59\x08\x92\x91\xf9\x53\xb9\x71\x1d\x35\x33\x67\x34\x8b\xd5\x30"
    "\x81\xa5\x06\x08\x2b\x06\x01\x05\x05\x07\x01\x01\x04\x81\x98\x30"
    "\x81\x95\x30\x27\x06\x08\x2b\x06\x01\x05\x05\x07\x30\x01\x86\x1b"
    "\x68\x74\x74\x70\x3a\x2f\x2f\x63\x65\x72\x74\x69\x6e\x66\x6f\x2e"
    "\x6d\x65\x2e\x63\x6f\x6d\x2f\x6f\x63\x73\x70\x30\x44\x06\x08\x2b"
    "\x06\x01\x05\x05\x07\x30\x02\x86\x38\x68\x74\x74\x70\x3a\x2f\x2f"
    "\x77\x77\x77\x2e\x61\x70\x70\x6c\x65\x2e\x63\x6f\x6d\x2f\x63\x65"
    "\x72\x74\x69\x66\x69\x63\x61\x74\x65\x61\x75\x74\x68\x6f\x72\x69"
    "\x74\x79\x2f\x63\x61\x73\x69\x67\x6e\x65\x72\x73\x2e\x68\x74\x6d"
    "\x6c\x30\x24\x06\x03\x55\x1d\x12\x86\x1d\x68\x74\x74\x70\x3a\x2f"
    "\x2f\x63\x65\x72\x74\x69\x6e\x66\x6f\x2e\x6d\x65\x2e\x63\x6f\x6d"
    "\x2f\x43\x41\x2e\x63\x65\x72\x30\x82\x01\x28\x06\x03\x55\x1d\x20"
    "\x04\x82\x01\x1f\x30\x82\x01\x1b\x30\x82\x01\x17\x06\x09\x2a\x86"
    "\x48\x86\xf7\x63\x64\x05\x02\x30\x82\x01\x08\x30\x40\x06\x08\x2b"
    "\x06\x01\x05\x05\x07\x02\x01\x16\x34\x68\x74\x74\x70\x3a\x2f\x2f"
    "\x77\x77\x77\x2e\x61\x70\x70\x6c\x65\x2e\x63\x6f\x6d\x2f\x63\x65"
    "\x72\x74\x69\x66\x69\x63\x61\x74\x65\x61\x75\x74\x68\x6f\x72\x69"
    "\x74\x79\x2f\x74\x65\x72\x6d\x73\x2e\x68\x74\x6d\x6c\x30\x81\xc3"
    "\x06\x08\x2b\x06\x01\x05\x05\x07\x02\x02\x30\x81\xb6\x1a\x81\xb3"
    "\x52\x65\x6c\x69\x61\x6e\x63\x65\x20\x6f\x6e\x20\x74\x68\x69\x73"
    "\x20\x63\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x20\x62\x79\x20"
    "\x61\x6e\x79\x20\x70\x61\x72\x74\x79\x20\x61\x73\x73\x75\x6d\x65"
    "\x73\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6f\x66\x20"
    "\x74\x68\x65\x20\x74\x68\x65\x6e\x20\x61\x70\x70\x6c\x69\x63\x61"
    "\x62\x6c\x65\x20\x73\x74\x61\x6e\x64\x61\x72\x64\x20\x74\x65\x72"
    "\x6d\x73\x20\x61\x6e\x64\x20\x63\x6f\x6e\x64\x69\x74\x69\x6f\x6e"
    "\x73\x20\x6f\x66\x20\x75\x73\x65\x2c\x20\x63\x65\x72\x74\x69\x66"
    "\x69\x63\x61\x74\x65\x20\x70\x6f\x6c\x69\x63\x79\x20\x61\x6e\x64"
    "\x20\x63\x65\x72\x74\x69\x66\x69\x63\x61\x74\x69\x6f\x6e\x20\x70"
    "\x72\x61\x63\x74\x69\x63\x65\x20\x73\x74\x61\x74\x65\x6d\x65\x6e"
    "\x74\x73\x2e\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x05"
    "\x05\x00\x03\x82\x01\x01\x00\x39\xb1\x81\xbe\x55\xf1\xb1\xe4\x16"
    "\x5d\x7c\x5b\x6a\xe8\xcf\xee\xaa\x87\x91\x81\xf2\x57\x0d\x32\x6c"
    "\xc6\x47\xdc\x71\x70\xfa\x7c\x47\x84\x7f\xa5\x69\x1b\x4c\x52\x98"
    "\x7f\xc8\x1f\x62\x06\x83\xae\x0a\xef\x55\x29\x35\xb3\xa0\x04\x88"
    "\xa6\x45\x0a\xd0\xd7\x4e\x5c\x63\x3e\xe7\xb2\x28\x85\xd3\x01\x56"
    "\x2b\x89\xb5\x60\x9a\xa5\x9d\x85\x0d\x76\x9e\xe1\x4a\x54\x8b\x6f"
    "\xad\xc4\xc2\x43\x2f\x18\xaa\x18\x1a\x64\x2f\x2e\xe3\xc9\xb8\xa8"
    "\xdd\xba\x53\xc4\x18\xcf\x4e\x30\xbf\x06\xa7\xdb\x12\x34\x24\x5c"
    "\x71\x60\x2a\xd2\x93\xef\x54\x83\x4e\x5d\xc5\x5f\x00\x8d\x02\x85"
    "\xe5\x17\x68\x46\xfa\xd4\x45\x96\x71\xf7\x93\x58\x4d\x83\x6b\x01"
    "\xcb\xdb\x7d\x61\x67\x69\xbe\xf1\x4c\x4b\xe2\x3e\xf6\x4e\x62\x77"
    "\x26\x86\xc4\x3b\x96\x38\x27\x0b\x02\x0d\x07\xc9\x95\x53\x6d\x03"
    "\xff\x61\xfb\x67\x7f\x8a\x2e\x2f\xc5\xff\x5a\xf9\x53\xd8\xb3\xae"
    "\xf1\x05\x27\x92\x79\x22\xd5\x55\x6e\xd6\xbf\xdb\x9d\xad\xbf\xbf"
    "\x7d\x15\xd8\x1c\x3d\x63\x86\xf1\xf1\x78\xfe\xfb\x62\x06\x8c\xf4"
    "\x0f\xa8\x91\xa8\x7c\xef\x51\x96\x09\x52\x68\xec\x09\xdd\xb9\x9a"
    "\x62\x49\xac\xbe\x20\x20\x9b\x30\x82\x06\x0d\x30\x82\x04\xf5\xa0"
    "\x03\x02\x01\x02\x02\x01\x0f\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7"
    "\x0d\x01\x01\x05\x05\x00\x30\x81\x86\x31\x0b\x30\x09\x06\x03\x55"
    "\x04\x06\x13\x02\x55\x53\x31\x1d\x30\x1b\x06\x03\x55\x04\x0a\x13"
    "\x14\x41\x70\x70\x6c\x65\x20\x43\x6f\x6d\x70\x75\x74\x65\x72\x2c"
    "\x20\x49\x6e\x63\x2e\x31\x2d\x30\x2b\x06\x03\x55\x04\x0b\x13\x24"
    "\x41\x70\x70\x6c\x65\x20\x43\x6f\x6d\x70\x75\x74\x65\x72\x20\x43"
    "\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x20\x41\x75\x74\x68\x6f"
    "\x72\x69\x74\x79\x31\x29\x30\x27\x06\x03\x55\x04\x03\x13\x20\x41"
    "\x70\x70\x6c\x65\x20\x52\x6f\x6f\x74\x20\x43\x65\x72\x74\x69\x66"
    "\x69\x63\x61\x74\x65\x20\x41\x75\x74\x68\x6f\x72\x69\x74\x79\x30"
    "\x1e\x17\x0d\x30\x35\x30\x32\x31\x30\x32\x30\x33\x38\x32\x37\x5a"
    "\x17\x0d\x31\x31\x31\x31\x31\x30\x32\x30\x33\x38\x32\x37\x5a\x30"
    "\x81\x86\x31\x0b\x30\x09\x06\x03\x55\x04\x06\x13\x02\x55\x53\x31"
    "\x1d\x30\x1b\x06\x03\x55\x04\x0a\x13\x14\x41\x70\x70\x6c\x65\x20"
    "\x43\x6f\x6d\x70\x75\x74\x65\x72\x2c\x20\x49\x6e\x63\x2e\x31\x2d"
    "\x30\x2b\x06\x03\x55\x04\x0b\x13\x24\x41\x70\x70\x6c\x65\x20\x43"
    "\x6f\x6d\x70\x75\x74\x65\x72\x20\x43\x65\x72\x74\x69\x66\x69\x63"
    "\x61\x74\x65\x20\x41\x75\x74\x68\x6f\x72\x69\x74\x79\x31\x29\x30"
    "\x27\x06\x03\x55\x04\x03\x13\x20\x41\x70\x70\x6c\x65\x20\x2e\x4d"
    "\x61\x63\x20\x43\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x20\x41"
    "\x75\x74\x68\x6f\x72\x69\x74\x79\x30\x82\x01\x22\x30\x0d\x06\x09"
    "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x01\x05\x00\x03\x82\x01\x0f\x00"
    "\x30\x82\x01\x0a\x02\x82\x01\x01\x00\xbb\x73\x84\xb0\x48\x36\x64"
    "\xf8\x1f\xa2\x57\x89\xb6\xe2\x71\x3c\x36\x5e\x56\xeb\xdb\x96\x16"
    "\x23\x1c\x81\xd0\x14\x2d\xd6\xf0\x4b\x22\x9b\x3f\xb7\x7a\x2c\xa2"
    "\xf0\x69\x48\x33\xb7\x9e\xef\x68\xe7\xbc\x30\x07\x73\xbc\x61\xb0"
    "\x01\x51\xef\x44\xdf\xdb\x45\x04\x96\x80\x2c\x7b\xe8\x93\x1f\x89"
    "\x92\x60\x21\xcd\x34\x55\x00\x66\x31\x03\x01\x01\x44\x25\x94\x0b"
    "\x42\x78\xca\x5a\x05\x1e\x77\x73\x24\x75\x6a\xc8\x45\x9c\xef\x2b"
    "\x2a\x51\x29\x8f\xeb\x7e\x62\xd7\xfa\xcd\x32\xfd\x31\xe8\xcd\xde"
    "\xab\x0d\xb5\xb4\x56\xc2\x68\x51\x09\x0c\x29\xe5\x38\x7b\x50\x68"
    "\xbe\x00\x87\x8c\x56\xef\xd3\x1b\xa3\xc9\x6e\xa6\x74\x43\xeb\x83"
    "\xd4\x63\x5f\x13\x79\x1e\xf8\x85\xbf\xbf\x73\x69\x36\xc5\x56\x12"
    "\x6c\xe4\xee\xaf\x86\xab\x65\xb6\x04\xf0\x5a\x63\x2d\xa3\x31\x6c"
    "\xe8\x48\x10\x65\xc0\x74\x45\x0d\x97\x58\x90\x3d\x91\x83\x14\xf2"
    "\x6f\xba\xad\x2f\x6c\x41\x6e\x3c\xb7\x8f\x72\x4a\x1d\xf0\xb7\x1a"
    "\xc0\xf0\x72\x0b\x3d\x9d\x7a\x8b\x4d\xb0\x33\xb7\x5f\x83\xef\x08"
    "\x5b\x5f\x35\x35\x3b\x52\xdf\x30\xb1\x00\x6c\xa6\x3a\x86\xc4\xf4"
    "\x7c\xe1\x79\x74\x5f\x0b\x35\xb8\xe1\x02\x03\x01\x00\x01\xa3\x82"
    "\x02\x82\x30\x82\x02\x7e\x30\x0e\x06\x03\x55\x1d\x0f\x01\x01\xff"
    "\x04\x04\x03\x02\x01\x86\x30\x0f\x06\x03\x55\x1d\x13\x01\x01\xff"
    "\x04\x05\x30\x03\x01\x01\xff\x30\x1d\x06\x03\x55\x1d\x0e\x04\x16"
    "\x04\x14\x7a\x7d\x90\xb1\x30\x59\x08\x92\x91\xf9\x53\xb9\x71\x1d"
    "\x35\x33\x67\x34\x8b\xd5\x30\x1f\x06\x03\x55\x1d\x23\x04\x18\x30"
    "\x16\x80\x14\x2b\xd0\x69\x47\x94\x76\x09\xfe\xf4\x6b\x8d\x2e\x40"
    "\xa6\xf7\x47\x4d\x7f\x08\x5e\x30\x82\x01\x28\x06\x03\x55\x1d\x20"
    "\x04\x82\x01\x1f\x30\x82\x01\x1b\x30\x82\x01\x17\x06\x09\x2a\x86"
    "\x48\x86\xf7\x63\x64\x05\x02\x30\x82\x01\x08\x30\x40\x06\x08\x2b"
    "\x06\x01\x05\x05\x07\x02\x01\x16\x34\x68\x74\x74\x70\x3a\x2f\x2f"
    "\x77\x77\x77\x2e\x61\x70\x70\x6c\x65\x2e\x63\x6f\x6d\x2f\x63\x65"
    "\x72\x74\x69\x66\x69\x63\x61\x74\x65\x61\x75\x74\x68\x6f\x72\x69"
    "\x74\x79\x2f\x74\x65\x72\x6d\x73\x2e\x68\x74\x6d\x6c\x30\x81\xc3"
    "\x06\x08\x2b\x06\x01\x05\x05\x07\x02\x02\x30\x81\xb6\x1a\x81\xb3"
    "\x52\x65\x6c\x69\x61\x6e\x63\x65\x20\x6f\x6e\x20\x74\x68\x69\x73"
    "\x20\x63\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x20\x62\x79\x20"
    "\x61\x6e\x79\x20\x70\x61\x72\x74\x79\x20\x61\x73\x73\x75\x6d\x65"
    "\x73\x20\x61\x63\x63\x65\x70\x74\x61\x6e\x63\x65\x20\x6f\x66\x20"
    "\x74\x68\x65\x20\x74\x68\x65\x6e\x20\x61\x70\x70\x6c\x69\x63\x61"
    "\x62\x6c\x65\x20\x73\x74\x61\x6e\x64\x61\x72\x64\x20\x74\x65\x72"
    "\x6d\x73\x20\x61\x6e\x64\x20\x63\x6f\x6e\x64\x69\x74\x69\x6f\x6e"
    "\x73\x20\x6f\x66\x20\x75\x73\x65\x2c\x20\x63\x65\x72\x74\x69\x66"
    "\x69\x63\x61\x74\x65\x20\x70\x6f\x6c\x69\x63\x79\x20\x61\x6e\x64"
    "\x20\x63\x65\x72\x74\x69\x66\x69\x63\x61\x74\x69\x6f\x6e\x20\x70"
    "\x72\x61\x63\x74\x69\x63\x65\x20\x73\x74\x61\x74\x65\x6d\x65\x6e"
    "\x74\x73\x2e\x30\x43\x06\x03\x55\x1d\x1f\x04\x3c\x30\x3a\x30\x38"
    "\xa0\x36\xa0\x34\x86\x32\x68\x74\x74\x70\x3a\x2f\x2f\x77\x77\x77"
    "\x2e\x61\x70\x70\x6c\x65\x2e\x63\x6f\x6d\x2f\x63\x65\x72\x74\x69"
    "\x66\x69\x63\x61\x74\x65\x61\x75\x74\x68\x6f\x72\x69\x74\x79\x2f"
    "\x72\x6f\x6f\x74\x2e\x63\x72\x6c\x30\x81\xa9\x06\x08\x2b\x06\x01"
    "\x05\x05\x07\x01\x01\x04\x81\x9c\x30\x81\x99\x30\x44\x06\x08\x2b"
    "\x06\x01\x05\x05\x07\x30\x02\x86\x38\x68\x74\x74\x70\x3a\x2f\x2f"
    "\x77\x77\x77\x2e\x61\x70\x70\x6c\x65\x2e\x63\x6f\x6d\x2f\x63\x65"
    "\x72\x74\x69\x66\x69\x63\x61\x74\x65\x61\x75\x74\x68\x6f\x72\x69"
    "\x74\x79\x2f\x63\x61\x73\x69\x67\x6e\x65\x72\x73\x2e\x68\x74\x6d"
    "\x6c\x30\x51\x06\x03\x55\x1d\x12\x86\x4a\x68\x74\x74\x70\x3a\x2f"
    "\x2f\x77\x77\x77\x2e\x61\x70\x70\x6c\x65\x2e\x63\x6f\x6d\x2f\x63"
    "\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x61\x75\x74\x68\x6f\x72"
    "\x69\x74\x79\x2f\x41\x70\x70\x6c\x65\x43\x6f\x6d\x70\x75\x74\x65"
    "\x72\x52\x6f\x6f\x74\x43\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65"
    "\x2e\x63\x65\x72\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01"
    "\x05\x05\x00\x03\x82\x01\x01\x00\x16\x06\xe5\x56\x65\x44\x7d\xd0"
    "\xaa\x99\x29\xe5\xc6\x97\x0b\x02\x43\x25\x88\x8c\x42\xba\xfb\xd6"
    "\x5b\xb7\x20\x10\x69\x04\x4e\x91\x81\x08\xec\xf5\x23\x1f\xd2\x6d"
    "\x3f\x35\xae\xdb\xff\xb8\xc9\x2b\x4b\x28\x73\xc4\x26\x03\xe1\x92"
    "\x5e\xb2\x84\x0d\xa7\x13\xc6\x34\x54\xf1\x49\x1f\xa9\x47\x88\xb1"
    "\x40\x9b\xd3\x61\x93\x5b\xcf\xc7\x53\xe7\x9f\x54\x7b\x30\xc6\xb8"
    "\x3a\x89\x6f\x06\x09\x45\xa1\x94\x98\xbe\x8b\xea\x25\x7d\x91\x89"
    "\xf9\x27\x62\xb9\x5f\x2d\xea\xa9\xe7\x96\x5c\xbe\xe5\x84\x6d\xe8"
    "\x50\x27\xb4\xb1\xea\x9f\xf7\x92\x0d\x54\x86\xf0\x37\x31\x47\x0d"
    "\x54\xde\x91\xe8\x78\xe8\x61\x27\x7c\xc3\xea\xd0\xfc\x21\xa1\x08"
    "\xc8\xe5\x01\x0e\x15\xf5\x61\x60\xce\xff\xbd\x44\xd6\x8a\x1b\x67"
    "\xf8\x1f\x82\xe2\xa6\xb3\xfc\x3a\xc7\x30\xae\x93\x89\x29\x2e\x81"
    "\x43\x0c\x9b\xd5\x18\xa6\x74\x66\x7d\x1c\x79\xe6\x22\xef\xba\xf8"
    "\x23\xb3\xd3\x50\x76\x20\xde\x7a\x93\x91\x40\xcd\x16\xad\x82\x6a"
    "\xe6\xe7\x25\xf5\xb3\xbb\x36\x61\x38\x8f\xaf\x36\x5f\x4b\xae\xc1"
    "\xc6\x89\x99\xb1\xb1\xd9\xf1\xa3\x51\x50\xa1\x00\x3d\xdd\x16\x89"
    "\xcf\x35\x05\x62\xa0\x8b\x48\x0a\x31\x82\x01\x35\x30\x82\x01\x31"
    "\x02\x01\x01\x30\x81\x8e\x30\x81\x86\x31\x0b\x30\x09\x06\x03\x55"
    "\x04\x06\x13\x02\x55\x53\x31\x1d\x30\x1b\x06\x03\x55\x04\x0a\x13"
    "\x14\x41\x70\x70\x6c\x65\x20\x43\x6f\x6d\x70\x75\x74\x65\x72\x2c"
    "\x20\x49\x6e\x63\x2e\x31\x2d\x30\x2b\x06\x03\x55\x04\x0b\x13\x24"
    "\x41\x70\x70\x6c\x65\x20\x43\x6f\x6d\x70\x75\x74\x65\x72\x20\x43"
    "\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x20\x41\x75\x74\x68\x6f"
    "\x72\x69\x74\x79\x31\x29\x30\x27\x06\x03\x55\x04\x03\x13\x20\x41"
    "\x70\x70\x6c\x65\x20\x2e\x4d\x61\x63\x20\x43\x65\x72\x74\x69\x66"
    "\x69\x63\x61\x74\x65\x20\x41\x75\x74\x68\x6f\x72\x69\x74\x79\x02"
    "\x03\x47\x3d\x05\x30\x09\x06\x05\x2b\x0e\x03\x02\x1a\x05\x00\x30"
    "\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x01\x05\x00\x04\x81"
    "\x80\x6d\xba\xa5\x44\x89\x98\x2d\x5e\xc4\xf6\xc0\x1e\x36\x70\x63"
    "\x43\xf6\x61\x3c\x0b\x43\x32\x50\x54\x95\x1e\x51\x41\x17\xd2\x7f"
    "\x47\x00\x21\x92\x61\xbf\x42\x63\xa4\xc8\x3a\x7f\x8d\x36\xea\xf1"
    "\x2d\x9f\x0c\x30\xbc\xe1\x5e\x16\xea\xcc\x01\xdf\xbd\x6b\xc8\xc3"
    "\xad\x12\x0e\x6a\x4d\xd5\xad\x15\x41\xcd\xde\xb9\xf9\xf5\xf2\xdc"
    "\x65\xaf\x61\x28\x68\x40\x52\x59\xf8\xb8\xa6\xec\xce\xed\x5e\x16"
    "\x7b\xbd\x72\x5e\x6a\x6e\x8b\x29\xb2\x97\x22\xe9\x99\xa3\xd6\xa9"
    "\x0e\xb3\x5e\xd3\x18\x24\x06\x20\x78\xc8\xa7\xa8\xe7\x76\x3a\x8a"
    "\x19\x00\x00\x00\x00\x00\x00";

static size_t contentlen = 3367;


static int
test_ber(void)
{
    ContentInfo ci;
    size_t size;
    int ret;

    ret = decode_ContentInfo(contentdata, contentlen, &ci, &size);
    if (ret)
	return 1;

    return 0;
}

int
main(int argc, char **argv)
{
    int ret = 0;

    ret += test_ber();

    return ret;
}
