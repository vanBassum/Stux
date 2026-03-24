import { useEffect, useState } from "react"

export interface ReleaseInfo {
  version: string
  tag: string
  url: string
  appUrl: string | null
  wwwUrl: string | null
}

const REPO = "vanBassum/ESPSkeleton"

export function useLatestRelease() {
  const [release, setRelease] = useState<ReleaseInfo | null>(null)

  useEffect(() => {
    fetch(`https://api.github.com/repos/${REPO}/releases/latest`)
      .then((r) => (r.ok ? r.json() : null))
      .then((data) => {
        if (!data?.tag_name) return

        const version = data.tag_name.replace(/^v/, "")
        const assets = data.assets as { name: string; browser_download_url: string }[]

        setRelease({
          version,
          tag: data.tag_name,
          url: data.html_url,
          appUrl: assets.find((a) => a.name.endsWith("-app.bin"))?.browser_download_url ?? null,
          wwwUrl: assets.find((a) => a.name.endsWith("-www.bin"))?.browser_download_url ?? null,
        })
      })
      .catch(() => {})
  }, [])

  return release
}
