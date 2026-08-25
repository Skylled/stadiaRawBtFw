// 600f8c0a  FUN_600f8c0a  size=42 bytes
// --- callers ---
//   600a4820 FUN_600a4820
//   600a8108 FUN_600a8108
//   600a44bc FUN_600a44bc
//   600a6d70 FUN_600a6d70
// --- callees ---
//   600bb6dc FUN_600bb6dc


void FUN_600f8c0a(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_600bb6dc(param_1,1);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x16) = param_2;
  }
  return;
}


