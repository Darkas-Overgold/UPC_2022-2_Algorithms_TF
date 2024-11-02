#include "MenuPrincipal.h"
using namespace System;
using namespace System::Windows::Forms;
void main() {
	Application::EnableVisualStyles();
	Application::Run(gcnew(TFAlgoritmos::MenuPrincipal));
}