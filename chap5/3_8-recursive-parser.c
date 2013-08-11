void dcl(void)
{
	int ns;

	for (ns = 0; gettoket() == '*'; )
			ns++;
	dirdcl();
	while ( ns-- > 0)
			strcat(out, "pointer to");
}
