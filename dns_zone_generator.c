// This program generates a BIND DNS zone file configuration based on the arguments passed.
/* Example:
 ./zone domain primary_dns email serial_number name_server_01 name_server_01 text_record 'rdata for the text record'
 ./zone example.net ns1.example.net email.example.net 1 ns1.example.net ns2.example.net view 'some text'
*/

#include <cs50.h>
#include <stdio.h>


int main(int argc, string argv[])
{
	printf("$TTL    300 ; default TTL for the zone\n");
	printf("$ORIGIN %s. ; domain for unqualified records\n", argv[1]);
	printf("@\t\tIN\tSOA\t%s. %s. (\n", argv[2], argv[3]);
	printf("\t\t%s\t; Serial\n", argv[4]);
	printf("\t\t5m\t; Refresh\n");
	printf("\t\t1m\t; Retry\n");
	printf("\t\t10y\t; Expire\n");
	printf("\t\t1m )\t; Negative Cache TTL = nxdomain ttl\n");
	printf("\n");
	printf("@\t\tIN\t\tNS\t\t%s.\n", argv[5]);
	printf("@\t\tIN\t\tNS\t\t%s.\n", argv[6]);
	printf("\n");
	printf("%s.%s.   300      IN      TXT      '%s'\n", argv[7], argv[1], argv[8]);
}
