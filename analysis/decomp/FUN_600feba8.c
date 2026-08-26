// 600feba8  FUN_600feba8  size=400 bytes
// --- callers ---
//   600c68fc FUN_600c68fc
// --- callees ---
//   600f3b78 FUN_600f3b78
//   600c67ac FUN_600c67ac
//   6009506c FUN_6009506c
//   6009519c FUN_6009519c
//   600950bc FUN_600950bc
//   60094f58 FUN_60094f58
//   600feb2e FUN_600feb2e
//   600eef06 FUN_600eef06
//   60094d24 FUN_60094d24
//   600ef5be FUN_600ef5be
//   600f3e00 FUN_600f3e00


void FUN_600feba8(undefined2 param_1,char param_2,int param_3)

{
  int iVar1;
  undefined1 local_2da;
  undefined1 local_2d9;
  undefined1 auStack_2d8 [8];
  undefined1 auStack_2d0 [8];
  undefined1 auStack_2c8 [28];
  undefined1 auStack_2ac [24];
  undefined1 auStack_294 [628];
  int local_20;
  int local_1c;
  undefined2 local_16;
  undefined2 *local_14;
  
  local_16 = *(undefined2 *)(param_3 + 2);
  local_1c = 0;
  local_20 = 0;
  iVar1 = FUN_600f3e00(param_1,&local_2d9,auStack_2d8,&local_2da);
  if (((iVar1 != 0) && (local_1c = FUN_60094f58(local_2d9), local_1c != 0)) &&
     (local_20 = FUN_6009519c(auStack_2d8), local_20 != 0)) {
    local_14 = (undefined2 *)FUN_6009506c(param_1);
    iVar1 = FUN_600eef06(local_20,local_16,auStack_2c8,auStack_2ac,auStack_294);
    if ((iVar1 != 0) &&
       (iVar1 = FUN_600c67ac(param_1,local_1c,local_20,local_14,auStack_2d0,local_16), iVar1 == 0))
    {
      iVar1 = FUN_600ef5be(local_1c,local_20,auStack_2d0);
      if (iVar1 == 0) {
        if (param_2 == '\a') {
          FUN_600f3b78(param_1,local_16);
        }
      }
      else {
        if ((local_14 == (undefined2 *)0x0) &&
           (local_14 = (undefined2 *)FUN_600950bc(local_2d9,auStack_2d8,local_2da),
           local_14 != (undefined2 *)0x0)) {
          *local_14 = param_1;
          *(undefined1 *)(local_14 + 4) = local_2da;
          FUN_60094d24(local_14,0x1d0d,0);
        }
        if (local_14 != (undefined2 *)0x0) {
          FUN_600feb2e(local_14,param_2,param_3,auStack_2d0);
        }
      }
    }
  }
  return;
}


