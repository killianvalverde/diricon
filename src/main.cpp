/* diricon
 * Copyright (C) 2018-2023 Killian Valverde.
 *
 * This file is part of diricon.
 *
 * diricon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * diricon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with diricon. If not, see <http://www.gnu.org/licenses/>.
 */

#include <speed/speed.hpp>
#include <speed/speed_alias.hpp>

#include "program.hpp"


int main(int argc, char* argv[])
{
    spd::ap::arg_parser ap("diricon");
    ap.add_help_text("Apply pictures as directory icons recursively, editing the GNOME Virtual "
                     "File System directories metadata.\n");
    ap.add_key_value_arg({"--icon-files", "-if"}, "Icon files names.", {spd::ap::avt_t::STRING}, 1u,
                         ~0u);
    ap.add_help_arg({"--help"}, "Display this help and exit.");
    ap.add_gplv3_version_arg({"--version"}, "Output version information and exit", "1.0.0", "2023",
                             "Killian Valverde");
    ap.add_keyless_arg("DIR", "Dir", "", {spd::ap::avt_t::RWX_DIR});
    ap.parse_args((unsigned int)argc, argv);
    
    diricon::program prog(
            ap.get_front_arg_value_as<std::filesystem::path>("DIR"),
            ap.get_arg_values_as<std::string>("--icon-files",
                                              {".icon.jpg", ".icon.jpeg", ".icon.png"})
    );
    
    return prog.execute();
}
