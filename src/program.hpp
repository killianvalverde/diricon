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

//
// Created by Killian on 13/07/18.
//

#ifndef APPLY_DIRECTORY_ICON_PROGRAM_HPP
#define APPLY_DIRECTORY_ICON_PROGRAM_HPP

#include <filesystem>
#include <set>
#include <string>


namespace diricon {


class program
{
public:
    program(
            std::filesystem::path src_pth,
            std::vector<std::string> icon_nmes
    ) noexcept;
    
    int execute();

private:
    bool execute_in_directory(const std::filesystem::path& dir_pth);
    
    void visit_inode(const std::filesystem::path& dir_pth);
    
    bool is_inode_visited(const std::filesystem::path& dir_pth) const noexcept;
    
    bool apply_icon(
            const std::filesystem::path& dir_pth,
            const std::filesystem::path& icon_pth
    ) const;

private:
    std::filesystem::path src_pth_;
    
    std::vector<std::string> icon_nmes_;
    
    std::set<std::uint64_t> vistd_inos_;
};


}


#endif
