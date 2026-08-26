// 60101b5a  FUN_60101b5a  size=28 bytes
// --- callers ---
//   60057ff0 FUN_60057ff0
//   600cbebc logger__600cbebc
// --- callees ---


undefined1 FUN_60101b5a(int *param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = param_1[2];
  if (param_2 <= uVar2) {
    param_3 = *param_1;
    uVar1 = 0;
    param_1[2] = param_2;
  }
  else {
    uVar1 = 0xb;
  }
  if (param_2 <= uVar2) {
    *(undefined1 *)(param_3 + param_2) = uVar1;
    *(undefined1 *)((int)param_1 + 0xd) = uVar1;
  }
  else {
    *(undefined1 *)((int)param_1 + 0xd) = uVar1;
    *(undefined1 *)(param_1 + 3) = uVar1;
  }
  return *(undefined1 *)((int)param_1 + 0xd);
}


