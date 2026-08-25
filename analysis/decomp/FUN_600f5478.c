// 600f5478  FUN_600f5478  size=182 bytes
// --- callers ---
//   600aed40 FUN_600aed40
//   600adeb4 FUN_600adeb4
// --- callees ---
//   600ad4f4 FUN_600ad4f4
//   600f4f02 FUN_600f4f02


char FUN_600f5478(undefined4 param_1,int *param_2,char param_3,ushort param_4,undefined2 param_5,
                 undefined4 param_6,undefined4 param_7,undefined2 param_8,undefined1 param_9,
                 undefined1 param_10,undefined4 param_11)

{
  undefined4 local_14;
  undefined4 *local_10;
  char local_9;
  
  local_9 = '\n';
  local_14 = param_6;
  if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
    local_10 = (undefined4 *)*param_2;
    while( true ) {
      if (local_10 == (undefined4 *)0x0) {
        return '\n';
      }
      if (param_4 < *(ushort *)(local_10 + 3)) {
        return '\n';
      }
      if (param_4 == *(ushort *)(local_10 + 3)) break;
      local_10 = (undefined4 *)*local_10;
    }
    local_9 = FUN_600f4f02(local_10,param_5,&local_14,param_3 == '\f',param_8,param_7,param_9,
                           param_10);
    if (local_9 == -0x78) {
      local_9 = FUN_600ad4f4(param_1,param_3,*(undefined2 *)(local_10 + 3),param_5,param_11);
    }
  }
  return local_9;
}


