// 600fee40  FUN_600fee40  size=210 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
// --- callees ---
//   60094ffc FUN_60094ffc
//   600952fc FUN_600952fc
//   60094f58 FUN_60094f58
//   600f3ed6 FUN_600f3ed6
//   600f7c42 FUN_600f7c42
//   600c69dc FUN_600c69dc
//   600fed9e FUN_600fed9e


void FUN_600fee40(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 local_d;
  undefined4 *local_c;
  
  local_d = 0x80;
  local_c = (undefined4 *)FUN_60094f58(*(undefined1 *)(param_2 + 0xc));
  if ((local_c != (undefined4 *)0x0) &&
     (iVar1 = FUN_600952fc(*(undefined1 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 8),
                           *(undefined1 *)(param_2 + 0xd),1,param_2,param_1), iVar1 != 0)) {
    iVar1 = FUN_600f3ed6(*(undefined1 *)(param_2 + 0xc),*(undefined1 *)(param_2 + 0xd),
                         *(undefined4 *)(param_2 + 8));
    if (iVar1 == 0) {
      local_d = 0x85;
      (*(code *)*local_c)(0x10,&local_d);
    }
    else {
      local_d = 0;
      (*(code *)*local_c)(0x10,&local_d);
      if (*(char *)(param_2 + 0xd) != '\0') {
        if (*(int *)(param_2 + 8) == 0) {
          FUN_600c69dc(*(undefined1 *)(param_2 + 0xc));
        }
        else {
          iVar1 = FUN_600f7c42(*(undefined4 *)(param_2 + 8));
          if ((iVar1 == 1) &&
             (iVar1 = FUN_60094ffc(*(undefined1 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 8),2),
             iVar1 == 0)) {
            FUN_600fed9e(*(undefined1 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 8));
          }
        }
      }
    }
  }
  return;
}


