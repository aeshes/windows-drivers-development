#include <ntddk.h>

void Unload(_In_ PDRIVER_OBJECT DriverObject)
{
	UNREFERENCED_PARAMETER(DriverObject);

	KdPrint(("Sample driver Unload called\n"));
}

void PrintVersion() {
	RTL_OSVERSIONINFOW info;
	info.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW);

	if (NT_SUCCESS(RtlGetVersion(&info))) {
		KdPrint(("Windows Major Version : %d\n", info.dwMajorVersion));
		KdPrint(("Windows Minor Version : %d\n", info.dwMinorVersion));
		KdPrint(("Windows Build         : %d\n", info.dwBuildNumber));
	}
}

extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = Unload;

	PrintVersion();

	return STATUS_SUCCESS;
}