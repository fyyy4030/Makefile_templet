#include <stdio.h>
#include <string.h>
#include <foo.h>
#include <bar.h>
#include <crc.h>
#include "hello.h"
#include "debug.h"

#include "version.h"

static void nogood(void)
{
    printf("no good %s.\n", "nogood");
}

int main(void)
{
    printf("hello from %s() %s.\n", __func__, VERSION_STRING);
    
    hello();

    hello_foo();
    hello_bar();
    nogood();
    /////////////////////////
    int crc = 0;
    const char* buf = "voice from hell....";
    crc = crc32((unsigned char *)buf, strlen(buf));
    printf("crc: 0x%x\n", crc);
    dump(buf, strlen(buf));
    return 0;
}