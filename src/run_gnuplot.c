#include "main.ih"

void run_gnuplot(char const *script, char const *outfile)
{
  char cmd[300];               // 300 is enough for the command in the next line
  sprintf(cmd, "gnuplot -e \"outfile='%s'\" %s/%s && rm data",
          outfile, SCRDIR, script);
  system(cmd);
}
