// 600f552e  FUN_600f552e  size=118 bytes
// --- callers ---
//   600adeb4 FUN_600adeb4
// --- callees ---
//   600ad130 FUN_600ad130


undefined1
FUN_600f552e(int *param_1,undefined1 param_2,ushort param_3,undefined1 param_4,undefined1 param_5)

{
  undefined4 *local_10;
  undefined1 local_9;
  
  local_9 = 10;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    local_10 = (undefined4 *)*param_1;
    while( true ) {
      if (local_10 == (undefined4 *)0x0) {
        return 10;
      }
      if (param_3 < *(ushort *)(local_10 + 3)) {
        return 10;
      }
      if (param_3 == *(ushort *)(local_10 + 3)) break;
      local_10 = (undefined4 *)*local_10;
    }
    local_9 = FUN_600ad130(local_10,0,param_2,param_4,param_5);
  }
  return local_9;
}


