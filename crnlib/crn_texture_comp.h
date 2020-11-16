// File: crn_texture_comp.h
// This software is in the public domain. Please see license.txt.
#pragma once

#include <crunch/crnlib.h>

namespace crnlib
{
   class mipmapped_texture;

   class itexture_comp
   {
      CRNLIB_NO_COPY_OR_ASSIGNMENT_OP(itexture_comp);

   public:
      itexture_comp() { }
      virtual ~itexture_comp() { }

      virtual const char *get_ext() const = 0;

      virtual bool compress_init(const crn_comp_params& params) = 0;
      virtual bool compress_pass(const crn_comp_params& params, float *pEffective_bitrate) = 0;
      virtual void compress_deinit() = 0;

      virtual const crnlib::vector<uint8>& get_comp_data() const = 0;
      virtual       crnlib::vector<uint8>& get_comp_data() = 0;
   };

   bool create_compressed_texture(const crn_comp_params &params, crnlib::vector<uint8> &comp_data, uint32 *pActual_quality_level, float *pActual_bitrate);
   bool create_texture_mipmaps(mipmapped_texture &work_tex, const crn_comp_params &params, const crn_mipmap_params &mipmap_params, bool generate_mipmaps);
   bool create_compressed_texture(const crn_comp_params &params, const crn_mipmap_params &mipmap_params, crnlib::vector<uint8> &comp_data, uint32 *pActual_quality_level, float *pActual_bitrate);

} // namespace crnlib
