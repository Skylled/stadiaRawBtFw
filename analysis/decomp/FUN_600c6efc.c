// 600c6efc  FUN_600c6efc  size=80 bytes
// --- callers ---
// --- callees ---
//   600ab564 FUN_600ab564


void FUN_600c6efc(int param_1,undefined4 param_2)

{
  undefined1 local_20 [2];
  undefined2 local_1e;
  undefined1 local_1c;
  int local_c;
  
  local_c = (uint)*(byte *)(param_1 + 0x17) * 0x20 + DAT_600c6f4c + 4;
  FUN_600ab564(*(undefined2 *)(param_1 + 0x14));
  local_20[0] = *(undefined1 *)(local_c + 0x1c);
  local_1e = *(undefined2 *)(param_1 + 0x14);
  local_1c = 0;
  if (*(int *)(local_c + 0x18) != 0) {
    (**(code **)(local_c + 0x18))(0xd,local_20,local_20,*(code **)(local_c + 0x18),param_2);
  }
  return;
}


