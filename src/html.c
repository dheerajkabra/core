/* 
   Copyright (C) Cfengine AS

   This file is part of Cfengine 3 - written and maintained by Cfengine AS.
 
   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; version 3.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License  
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA

  To the extent this program is licensed as part of the Enterprise
  versions of Cfengine, the applicable Commerical Open Source License
  (COSL) may apply to this file if you as a licensee so wish it. See
  included file COSL.txt.

*/

/*****************************************************************************/
/*                                                                           */
/* File: html.c                                                              */
/*                                                                           */
/*****************************************************************************/

#include "cf3.defs.h"
#include "cf3.extern.h"

/*****************************************************************************/

void CfHtmlHeader(FILE *fp,char *title,char *css,char *webdriver,char *header)
{
#ifndef HAVE_CFLIBNOVA

if (title == NULL)
   {
   title = "Cfengine Knowledge";
   }
 
fprintf(fp,"<html>"
        "  <head>"
        "    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />"
        "    <title>"
        "      %s"
        "    </title>"
        "    <link rel=\"stylesheet\" href=\"%s\" type=\"text/css\" media=\"screen\" />"
        "    <link rel=\"stylesheet\" href=\"hand_%s\" type=\"text/css\" media=\"handheld\" />"
        "  </head>"
        "  <body>",title,css,css);
#endif

if (header && strlen(header) > 0)
   {
   if (strlen(LICENSE_COMPANY) > 0)
      {
      fprintf(fp,"<div id=\"company\">%s</div>\n%s\n",LICENSE_COMPANY,header);
      }
   else
      {
      fprintf(fp,"%s\n",header);
      }
   }

if (title)
   {
   fprintf(fp,"<h1>%s</h1>",title);
   fprintf(fp,"<div id=\"primary\">\n");
   }
}

/*****************************************************************************/

void CfHtmlFooter(FILE *fp,char *footer)
{
if (strlen(footer) > 0)
   {
   fprintf(fp,"%s",footer);
   }

#ifndef HAVE_CFLIBNOVA
fprintf(fp,"</div></body></html>\n");
#endif
}

/*********************************************************************/

char *URLControl(char *driver,char *url)

{ static char transform[CF_BUFSIZE];

if (strncmp(url,"http",4) == 0)
   {
   return url;
   }

snprintf(transform,CF_BUFSIZE-1,"%s?quote=%s",driver,url);

return transform;
}


