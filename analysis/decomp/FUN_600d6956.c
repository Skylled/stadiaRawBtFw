// 600d6956  FUN_600d6956  size=14 bytes
// --- callers ---
//   600d6a6e FUN_600d6a6e
//   600649d4 usb_host_hid__600649d4
//   600d6964 FUN_600d6964
//   600d69de FUN_600d69de
// --- callees ---
//   600d15c4 private_heap__600835ac


void FUN_600d6956(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  if (iVar1 != 0) {
    private_heap__600835ac(iVar1);
    return;
  }
  return;
}


