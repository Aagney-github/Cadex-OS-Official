/*
    * Copyright (C) 2019-2020 OpenCreeck
    * This software is distributed under the GNU General Public License.
    * See the file LICENSE for details.
    * 
    * Who Am I ? 
    * 
    * NOTE: This is fake because the sudo system is not yet implemented
*/
#include <library/stdio.h>
#include <passwd.h>

                 int main(int argc, char **argv)
{
    struct passwd *p = getpwuid(getprocuid());
    if (!p)
        return 0;

    printf("%s\n", p->pw_name);

    return 0;
}
