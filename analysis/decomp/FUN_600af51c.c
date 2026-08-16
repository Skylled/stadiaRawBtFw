// 600af51c  FUN_600af51c  size=116 bytes
// --- callers ---
//   600ab9b8 FUN_600ab9b8
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6006ddd8 FUN_6006ddd8
//   600d9250 FUN_600d9250


void FUN_600af51c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_d;
  undefined4 local_c;
  
  local_c = DAT_600af590;
  for (local_d = 0; local_d < 10; local_d = local_d + 1) {
    iVar1 = thunk_EXT_FUN_0000b554(param_1,local_c + 8,0x14);
    if (iVar1 == 0) {
      while (*(int *)(local_c + 0x40) != 0) {
        uVar2 = FUN_600d9250(local_c + 0x40);
        FUN_6006ddd8(uVar2,DAT_600af594,0x189);
      }
      *(undefined4 *)(local_c + 0x4c) = 0;
      *(undefined4 *)(local_c + 0x3c) = 0;
      *(undefined4 *)(local_c + 0x38) = 0;
    }
    local_c = local_c + 0x58;
  }
  return;
}


