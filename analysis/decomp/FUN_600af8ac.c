// 600af8ac  FUN_600af8ac  size=172 bytes
// --- callers ---
//   600f5bfc FUN_600f5bfc
//   600f5b32 FUN_600f5b32
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600af75c FUN_600af75c
//   600af85c FUN_600af85c
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d9246 FUN_600d9246


int FUN_600af8ac(undefined4 param_1,undefined1 param_2)

{
  bool bVar1;
  undefined4 local_10;
  undefined1 local_9;
  
  local_10 = 0;
  local_9 = FUN_600af75c(param_1,param_2);
  bVar1 = local_9 == 0xff;
  if (bVar1) {
    local_9 = FUN_600af85c();
  }
  if (local_9 != 0xff) {
    local_10 = (uint)local_9 * 0x10c + DAT_600af958;
    if (bVar1) {
      thunk_EXT_FUN_0000b5ba(local_10,0,0x10c);
      FUN_600d9246(local_10);
      FUN_600d9246(local_10 + 0x68);
      FUN_600d9246(local_10 + 0x100);
      *(undefined1 *)(local_10 + 0xfa) = 1;
      *(byte *)(local_10 + 0xfb) = local_9;
      *(undefined1 *)(local_10 + 0x13) = param_2;
    }
    thunk_EXT_FUN_0000b572(local_10 + 0xd,param_1,6);
  }
  return local_10;
}


