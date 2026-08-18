// 600d16ae  FUN_600d16ae  size=22 bytes
// --- callers ---
//   600567fc FUN_600567fc
//   600d334c FUN_600d334c
//   600d2ace FUN_600d2ace
//   600d3268 FUN_600d3268
//   600d32ee FUN_600d32ee
//   600569e4 FUN_600569e4
//   60057c78 FUN_60057c78
//   600d3386 FUN_600d3386
//   600d2298 FUN_600d2298
//   600d26a4 FUN_600d26a4
//   600d27b4 FUN_600d27b4
//   600d2dba FUN_600d2dba
//   60056fa4 FUN_60056fa4
//   600563b8 FUN_600563b8
//   600d29b8 FUN_600d29b8
//   600d2762 FUN_600d2762
//   600d32a2 FUN_600d32a2
//   600d2b6c FUN_600d2b6c
//   60056968 FUN_60056968
// --- callees ---
//   600c9e6c queue__600c9e6c


bool FUN_600d16ae(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    bVar1 = true;
  }
  else {
    iVar2 = queue__600c9e6c(*param_1);
    bVar1 = iVar2 == 0;
  }
  return bVar1;
}


