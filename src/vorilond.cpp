/*Vorilon is a VOIP Conferencing system
* Copyright (C) 2009,2010  Daniel Myers dan<at>moird.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include <iostream>
#include "ConfigData.hpp"
#include "ServerData.hpp"
#include "ErrorHandle.hpp"
#include "LogInt.hpp"

namespace VR = Vorilon;
int main(int argc, char* argv[]){
	try{
		VR::ServerData sData;
		VR::ConfigData ConD(&sData);
		ConD.ReadData();
	}
	catch (VR::Error::Exit_Command & e) {
		VR::Log::Msg(VR::Log::DEBUG, "Exit Command");
		VR::Log::Msg(VR::Log::DEBUG, diagnostic_information(e));
		return 0;
	}
	catch (boost::exception & e) {
		VR::Log::Msg(VR::Log::ERROR, "Vorilon Standard Exception");
		VR::Log::Msg(VR::Log::DEBUG, diagnostic_information(e));
	}
	catch (std::exception & e){
		VR::Log::Msg(VR::Log::ERROR, "Vorilon has experienced an error and is now exiting.");
		VR::Log::Msg(VR::Log::WARNING, e.what());
	}
	catch (...){
		std::cerr << "Vorilon as experienced a default unhandled exception and has exited." << std::endl <<
			boost::current_exception_diagnostic_information();
	}
	return 0;
}
