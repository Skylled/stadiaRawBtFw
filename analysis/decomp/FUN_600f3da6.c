// 600f3da6  FUN_600f3da6  size=90 bytes
// --- callers ---
//   600f3f50 FUN_600f3f50
//   600fde94 FUN_600fde94
//   600f32aa FUN_600f32aa
//   600ff404 FUN_600ff404
// --- callees ---
//   600f6dc6 FUN_600f6dc6
//   600f5a98 FUN_600f5a98
//   600f592e FUN_600f592e
//   600af7c8 FUN_600af7c8


undefined1 FUN_600f3da6(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  local_9 = 0x87;
  iVar1 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  if (iVar1 != 0) {
    FUN_600f5a98((char)param_1,iVar1,0,1);
    iVar2 = FUN_600f6dc6(iVar1);
    if (iVar2 == 0) {
      FUN_600f592e(iVar1);
    }
    local_9 = 0;
  }
  return local_9;
}


