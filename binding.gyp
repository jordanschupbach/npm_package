{
  "targets": [
    { 
      "target_name": "addon",
      "sources": [
        "src/**/*.cpp"
      ],
      "include_dirs": [
        "src",
        "<!@(node -p \"require('path').resolve('include')\")"
      ],
      "xcode_settings": {
        "HEADER_SEARCH_PATHS": ["<!@(node -p \"require('path').resolve('include')\")"]
      },
      "msvs_settings": {
        "VCCLCompilerTool": {
          "AdditionalIncludeDirectories": ["<!@(node -p \"require('path').resolve('include')\")"]
        }
      }
    }
  ]

}
