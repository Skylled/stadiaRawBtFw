// 600c6e94  FUN_600c6e94  size=100 bytes
// --- callers ---
// --- callees ---
//   600ab424 FUN_600ab424


void FUN_600c6e94(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_20 [2];
  undefined2 local_1e;
  undefined1 local_1c;
  int local_c;
  
  iVar1 = (uint)*(byte *)(param_1 + 0x17) * 0x20 + DAT_600c6ef8;
  local_c = iVar1 + 4;
  local_20[0] = *(undefined1 *)(iVar1 + 0x20);
  local_1e = *(undefined2 *)(param_2 + 6);
  iVar1 = FUN_600ab424(*(undefined1 *)(iVar1 + 0x20),*(undefined2 *)(param_1 + 0x14),
                       *(undefined1 *)(param_2 + 8));
  if (iVar1 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = 0x85;
  }
  if (*(int *)(local_c + 0x18) != 0) {
    (**(code **)(local_c + 0x18))(0xc,local_20);
  }
  return;
}


