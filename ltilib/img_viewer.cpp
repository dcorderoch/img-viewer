/*
 * Copyright (C) 2009 by David Cordero Chavarría
 * based on LTI-Lib-2 example by Dr Pablo Alvarado
 *
 * This file is part of an assignment for the course
 * CE-5201 Digital Image Processing and Analysis,
 * at the Costa Rica Institute of Technology.
 *
 * The LTI-Lib-2 is free software; you can redistribute it and/or
 * modify it under the terms of the BSD License.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the authors nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <ltiViewer2D.h>
#include <ltiIOImage.h>
#include <ltiIOLTI.h>

#include <iostream>
#include <cstdlib>

void show_help ()
{
  std::cout <<
    "usage: \n" \
    "viewer ([-h] | <image_file>)\n" \
    "    -h                   show this help\n" \
    "    <image_file>         input images/channels" << std::endl;
}

int main (int argc,char* argv[])
{
  // this runs only once, hence while (0);
  if (argc == 2)
  {
    lti::ioImage image_loader;
    lti::image the_image;

    lti::viewer2D::interaction needed_user_action;
    lti::ipoint point_of_action;

    std::string parameter = argv[1];

    if (parameter == "-h")
      show_help ();
    else
    {
      if (image_loader.load (parameter, the_image))
      {
        static lti::viewer2D viewer_window;
        lti::viewer2D::parameters vpar (viewer_window.getParameters());
        vpar.title = parameter;
        viewer_window.setParameters (vpar);

        if (!the_image.empty ())
        {
          viewer_window.show (the_image);
        }
        // without this line program crashes
        viewer_window.waitInteraction (needed_user_action, point_of_action);
      }
    }
  }
  else
    show_help ();

  exit (EXIT_SUCCESS);
}
